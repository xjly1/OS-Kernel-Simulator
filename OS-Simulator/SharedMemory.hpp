#pragma once
#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <unordered_map>
#include <set>
#include <queue>
#include <iostream>

#include "TCB.hpp"
#include "Semaphore.hpp"
#include "StateManager.hpp"

class SharedMemory {
private:
    struct Segment {
        std::unordered_map<int, int> data;
        std::set<int> allowedThreads;

        // Readers-Writers
        std::unordered_map<int, int> readersCount;
        std::unordered_map<int, Semaphore> readLock;
        std::unordered_map<int, Semaphore> writeLock;

        // Fairness
        bool writerWaiting = false;

        // FIX: لازم ترجع reference
        Semaphore& getReadLock(int key) {
            if (!readLock.count(key))
                readLock.emplace(key, Semaphore(1));
            return readLock[key];
        }

        Semaphore& getWriteLock(int key) {
            if (!writeLock.count(key))
                writeLock.emplace(key, Semaphore(1));
            return writeLock[key];
        }
    };

    std::unordered_map<int, Segment> segments;

public:

    // CREATE SEGMENT
    void createSegment(int segmentID, const std::set<int>& allowed) {
        segments[segmentID].allowedThreads = allowed;
    }

    // WRITE
    void write(TCB& t, int segmentID, int key, int value) {
        auto& seg = segments[segmentID];

        if (!seg.allowedThreads.count(t.TID)) {
            std::cout << "ACCESS DENIED (WRITE) T" << t.TID << "\n";
            return;
        }

        seg.writerWaiting = true;
        Semaphore& w = seg.getWriteLock(key);
        w.wait(t);

        if (t.state == State::WAITING) return;

        seg.data[key] = value;

        std::cout << "T" << t.TID
                  << " WRITE [" << segmentID << ":" << key
                  << "] = " << value << "\n";

        seg.writerWaiting = false;

        // WAKEUP FIX
        TCB* awakened = w.signal();

        if (awakened) {
            awakened->blockType = BlockType::NONE;
            StateManager::transition(*awakened, State::READY);
        }
    }

    // READ
    int read(TCB& t, int segmentID, int key) {
        auto& seg = segments[segmentID];

        if (!seg.allowedThreads.count(t.TID)) {
            std::cout << "ACCESS DENIED (READ) T" << t.TID << "\n";
            return -1;
        }

        // Fairness: إذا writer ينتظر → لا تدخل reader
        if (seg.writerWaiting) {
            t.blockType = BlockType::SEMAPHORE;
            StateManager::transition(t, State::WAITING);
            return -1;
        }

        Semaphore& r = seg.getReadLock(key);
        Semaphore& w = seg.getWriteLock(key);

        // ENTER READ
        r.wait(t);

        if (t.state == State::WAITING) return -1;

        seg.readersCount[key]++;

        if (seg.readersCount[key] == 1) {
            w.wait(t);

            if (t.state == State::WAITING) {
                seg.readersCount[key]--;
                
                // WAKEUP FIX
                TCB* aw = r.signal();

                if (aw) {
                    aw->blockType = BlockType::NONE;
                    StateManager::transition(*aw, State::READY);
                }

                return -1;
            }
        }

        // WAKEUP FIX
        {
            TCB* aw = r.signal();

            if (aw) {
                aw->blockType = BlockType::NONE;
                StateManager::transition(*aw, State::READY);
            }
        }

        // READ
        int val = seg.data[key];

        std::cout << "T" << t.TID
                  << " READ [" << segmentID << ":" << key
                  << "] = " << val << "\n";

        // EXIT READ
        r.wait(t);
        seg.readersCount[key]--;

        if (seg.readersCount[key] == 0) {

            TCB* aw = w.signal();
            if (aw) {
                aw->blockType = BlockType::NONE;
                StateManager::transition(*aw, State::READY);
            }
        }

        {
            TCB* aw = r.signal();
            if (aw) {
                aw->blockType = BlockType::NONE;
                StateManager::transition(*aw, State::READY);
            }
        }

        return val;
    }
};

#endif