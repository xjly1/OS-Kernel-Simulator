#pragma once
#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <queue>

#include "TCB.hpp"
#include "StateManager.hpp"

class Semaphore {
private:
    int value;
    std::queue<TCB*> waitingQueue;

public:

    // Constructor (default = 1)
    Semaphore(int init = 1) : value(init) {}

    // WAIT (P)
    void wait(TCB& thread) {
        value--;

        if (value < 0) {

            // يدخل قائمة الانتظار
            waitingQueue.push(&thread);

            // يتحول إلى blocked
            thread.blockType = BlockType::SEMAPHORE;
            StateManager::transition(thread, State::WAITING);
        }
    }

    // SIGNAL (V)
    TCB* signal() {
        value++;

        // إذا أكو thread منتظر
        if (value <= 0 && !waitingQueue.empty()) {

            TCB* next = waitingQueue.front();
            waitingQueue.pop();

            // لا نسوي wakeup هنا
            // فقط نرجع الـ thread للـ scheduler

            return next;
        }

        return nullptr;
    }

    // DEBUG / HELPERS
    int getValue() const {
        return value;
    }

    bool hasWaiting() const {
        return !waitingQueue.empty();
    }

    int waitingCount() const {
        return waitingQueue.size();
    }
};

#endif