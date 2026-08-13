#pragma once
#ifndef MUTEX_H
#define MUTEX_H

#include <vector>
#include <iostream>
#include <algorithm>

#include "TCB.hpp"
#include "StateManager.hpp"
#include "CASLock.hpp"

class Mutex {
private:
    TCB* owner = nullptr;

    // Nested locking count
    int lockCount = 0;

    // Spinlock
    CASLock spin;

    // Priority Queue
    std::vector<TCB*> waitingQueue;

public:
    static bool comparePriority(TCB* a, TCB* b) {
        return a->Priority < b->Priority;
    }

    // ACQUIRE
    void acquire(TCB& thread) {
        while (!spin.acquire());

        // Nested Lock
        if (owner == &thread) {
            lockCount++;
            spin.release();
            return;
        }

        // mutex free
        if (owner == nullptr) {
            owner = &thread;
            lockCount = 1;
            thread.savePriority();
            spin.release();
            return;
        }

        // Priority Inheritance
        if (thread.Priority < owner->Priority) {
            owner->Priority = thread.Priority;
        }

        // add to priority queue
        waitingQueue.push_back(&thread);
        std::sort(waitingQueue.begin(), waitingQueue.end(), comparePriority);
        thread.blockType = BlockType::MUTEX;
        StateManager::transition(thread, State::WAITING);
        spin.release();
    }

    // RELEASE
    TCB* release(TCB& thread) {

        while (!spin.acquire());

        if (owner != &thread) {
            std::cout << "ERROR: T" << thread.TID << " tried to release mutex without ownership!\n";
            spin.release();
            return nullptr;
        }

        // Nested unlock
        lockCount--;

        if (lockCount > 0) {
            spin.release();
            return nullptr;
        }

        // restore priority
        thread.restorePriority();

        if (!waitingQueue.empty()) {

            TCB* next = waitingQueue.front();
            waitingQueue.erase(waitingQueue.begin());
            owner = next;
            lockCount = 1;
            next->blockType = BlockType::NONE;
            next->savePriority();
            StateManager::transition(*next, State::READY);
            spin.release();
            return next;
        }

        owner = nullptr;
        spin.release();
        return nullptr;
    }

    TCB* getOwner() {
        return owner;
    }

    bool isOwnedBy(TCB& t) {
        return owner == &t;
    }

    bool isLocked() const {
        return owner != nullptr;
    }
};

#endif