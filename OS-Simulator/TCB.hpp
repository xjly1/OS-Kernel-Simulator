#pragma once
#ifndef TCB_H
#define TCB_H

#include <iostream>

#include "StateManager.hpp"
#include "CPU.hpp"

enum class BlockType {
    NONE, IO, MUTEX, SEMAPHORE, MESSAGE
};

class TCB {
public:
    CPU cpu;

    int TID;
    int parentPID;
    int Arrival_Time;
    int Burst_Time;
    int Remaining_Time;
    int Priority;
    int originalPriority;
    int Waiting_Time = 0;
    int Turnaround_Time = 0;

    State state;

    BlockType blockType = BlockType::NONE;

    bool needsCriticalSection = false;
    bool inCriticalSection = false;

    int nestedLocks = 0;
    int targetTID = -1;
    int messageData = 0;

    TCB(int tid, int pid, int at, int bt, int pr)
        : TID(tid), parentPID(pid),
          Arrival_Time(at), Burst_Time(bt),
          Remaining_Time(bt),
          Priority(pr), originalPriority(pr),
          state(State::NEW) {}

    void savePriority() { originalPriority = Priority; }
    void restorePriority() { Priority = originalPriority; }

    void print() const {
        std::cout << "T" << TID
                  << " (P" << parentPID << ")"
                  << " WT:" << Waiting_Time
                  << " TAT:" << Turnaround_Time
                  << " PR:" << Priority << "\n";
    }
};

#endif