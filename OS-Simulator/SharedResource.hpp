#pragma once
#ifndef SHARED_RESOURCE_H
#define SHARED_RESOURCE_H

#include <iostream>

#include "Mutex.hpp"
#include "TCB.hpp"

class SharedResource {
private:
    int counter;
    Mutex mtx;

public:
    SharedResource() : counter(0) {}

    void access(TCB& thread) {

        // إذا thread already blocked → لا تحاول
        if (thread.blockedByMutex)
            return;

        // محاولة الدخول
        mtx.acquire(thread);

        // إذا ما حصل lock → توقف
        if (!mtx.isOwnedBy(thread)) {
            thread.blockedByMutex = true;
            return;
        }

        // دخل Critical Section
        thread.inCriticalSection = true;

        std::cout << "T" << thread.TID << " ENTER CS\n";

        // --- Simulate work ---
        int temp = counter;

        std::cout << "T" << thread.TID << " reads: " << temp << "\n";

        temp++;
        counter = temp;

        std::cout << "T" << thread.TID << " writes: " << counter << "\n";

        // --- End work ---
        std::cout << "T" << thread.TID << " EXIT CS\n";

        thread.inCriticalSection = false;

        // تحرير الـ lock
        mtx.release();

        // إذا أكو Thread كان blocked → رجعه READY
        thread.blockedByMutex = false;
    }

    int getValue() const {
        return counter;
    }
};

#endif