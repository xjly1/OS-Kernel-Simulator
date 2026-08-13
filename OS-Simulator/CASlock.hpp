#pragma once
#ifndef CASLOCK_H
#define CASLOCK_H

#include <atomic>
#include <thread>

class CASLock {
    private:
        std::atomic<bool> locked;

    public:
        CASLock() : locked(false) {}

        // Spinlock acquire (real behavior)
        void acquire() {
            while (true) {
                bool expected = false;

                // حاول تمسك اللّوك
                if (locked.compare_exchange_weak(
                        expected, true,
                        std::memory_order_acquire)) {

                    return; // حصل اللّوك
                }

                // CPU-friendly spinning (مثل sched_yield)
                std::this_thread::yield();
            }
        }

        // Try lock (optional but مهم)
        bool tryAcquire() {
            bool expected = false;
            return locked.compare_exchange_strong(expected, true, std::memory_order_acquire);
        }

        // Release
        void release() {
            locked.store(false, std::memory_order_release);
        }

        bool isLocked() const {
            return locked.load(std::memory_order_relaxed);
        }
};

#endif