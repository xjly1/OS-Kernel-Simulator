#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>

// MEMORY
class Memory {
    public:
        std::vector<int> frames;

        Memory(int size) {
            frames.resize(size, -1);
        }

        int findFreeFrame() {
            for (int i = 0; i < frames.size(); i++) {
                if (frames[i] == -1)
                    return i;
            }
            return -1;
        }

        void setFrame(int frame, int page) {
            frames[frame] = page;
        }

        void printMemory() {
            std::cout << "Memory: ";
            for (int f : frames)
                std::cout << f << " ";
            std::cout << std::endl;
        }
};

// PAGE TABLE 
class PageTable {
    public:
        std::vector<int> table;

        PageTable(int pages) {
            table.resize(pages, -1);
        }
};

// PROCESS
class Process {
    public:
        int id;
        PageTable pt;
        std::vector<int> requests;
        int index = 0;

        Process(int id, int pages) : id(id), pt(pages) {}

        bool isFinished() {
            return index >= requests.size();
        }

        int nextRequest() {
            return requests[index++];
        }
};

// TLB
class TLB {
    private:
        int capacity;
        std::list<std::pair<int, int>> cache;
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

    public:
        TLB(int size) : capacity(size) {}

        bool lookup(int page, int& frame) {
            if (map.find(page) == map.end())
                return false;

            auto it = map[page];
            cache.splice(cache.begin(), cache, it);
            frame = it->second;
            return true;
        }

        void insert(int page, int frame) {
            if (map.find(page) != map.end()) {
                cache.erase(map[page]);
            }

            cache.push_front({ page, frame });
            map[page] = cache.begin();

            if (cache.size() > capacity) {
                auto last = cache.back();
                map.erase(last.first);
                cache.pop_back();
            }
        }

        // مهم: حذف صفحة من TLB
        void remove(int page) {
            if (map.find(page) != map.end()) {
                cache.erase(map[page]);
                map.erase(page);
            }
        }

        void flush() {
            cache.clear();
            map.clear();
        }

        void printTLB() {
            std::cout << "TLB: ";
            for (auto& p : cache)
                std::cout << "(" << p.first << "->" << p.second << ") ";
            std::cout << std::endl;
        }
};

// LRU
class LRU {
    private:
        std::list<int> pages;
        std::unordered_map<int, std::list<int>::iterator> map;

    public:
        void use(int page) {
            if (map.find(page) != map.end()) {
                pages.erase(map[page]);
            }

            pages.push_front(page);
            map[page] = pages.begin();
        }

        int getLRU() {
            if (pages.empty())
                return -1;

            int page = pages.back();
            pages.pop_back();
            map.erase(page);
            return page;
        }
};

// MMU
class MMU {
    public:
        int pageSize;
        Memory& memory;
        TLB tlb;
        LRU lru;

        // Statistics (مهم للمشروع)
        int tlbHits = 0;
        int tlbMisses = 0;
        int pageFaults = 0;

        MMU(int size, Memory& mem) : pageSize(size), memory(mem), tlb(3) {}

        int findFrameOfPage(int page) {
            for (int i = 0; i < memory.frames.size(); i++) {
                if (memory.frames[i] == page)
                    return i;
            }
            return -1;
        }

        // LRU Replacement مصحح
        int replaceLRU(Process& p) {
            int victimPage = lru.getLRU();

            if (victimPage == -1)
                return -1;

            int frame = findFrameOfPage(victimPage);

            std::cout << "LRU Replace Page " << victimPage << " at Frame " << frame << std::endl;

            // تنظيف Page Table
            if (victimPage < p.pt.table.size())
                p.pt.table[victimPage] = -1;

            // تنظيف TLB
            tlb.remove(victimPage);
            return frame;
        }

        int translate(Process& p, int logicalAddress) {
            int page = logicalAddress / pageSize;
            int offset = logicalAddress % pageSize;

            if (page >= p.pt.table.size()) {
                std::cout << "Invalid Address!\n";
                return -1;
            }

            int frame;

            // TLB
            if (tlb.lookup(page, frame)) {
                std::cout << "TLB HIT\n";
                tlbHits++;
            }
            else {
                std::cout << "TLB MISS\n";
                tlbMisses++;

                // PAGE FAULT
                if (p.pt.table[page] == -1) {
                    pageFaults++;
                    std::cout << "Page Fault (P" << p.id << ", Page " << page << ")\n";
                    frame = memory.findFreeFrame();

                    if (frame == -1) {
                        frame = replaceLRU(p);
                    }

                    memory.setFrame(frame, page);
                    p.pt.table[page] = frame;
                }

                else {
                    frame = p.pt.table[page];
                }

                tlb.insert(page, frame);
            }

            lru.use(page);
            int physical = frame * pageSize + offset;
            std::cout << "Logical " << logicalAddress << " → Physical " << physical << std::endl;
            memory.printMemory();
            tlb.printTLB();
            return physical;
        }

        void printStats() {
            std::cout << "\n===== MMU Stats =====\n";
            std::cout << "TLB Hits: " << tlbHits << std::endl;
            std::cout << "TLB Misses: " << tlbMisses << std::endl;
            std::cout << "Page Faults: " << pageFaults << std::endl;
        }
};

// MAIN
int main() {
    return 0;
}