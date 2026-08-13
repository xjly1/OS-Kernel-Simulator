#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1, mtx2;

void task() {
    lock(mtx1, mtx2); // يقفل الاثنين بدون deadlock

    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    
    std::cout << "Thread working\n";
}

int main() {
    
    return 0;
}