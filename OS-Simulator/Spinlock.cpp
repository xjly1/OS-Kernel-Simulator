#include <iostream>
#include <thread>
#include <atomic>

std::atomic_flag lock = ATOMIC_FLAG_INIT;

void spin_lock() {
    while (lock.test_and_set(std::memory_order_acquire)) {
        std::this_thread::yield(); // مهم جدًا
    }
}

void spin_unlock() {
    lock.clear(std::memory_order_release);
}

int counter = 0;

void work() {
    for (int i = 0; i < 100000; i++) {
        spin_lock();
        counter++;
        spin_unlock();
    }
}

int main() {
	return 0;
}