#pragma once
#ifndef OS_KERNEL_H
#define OS_KERNEL_H

#include <iostream>
#include <vector>

#include "SchedulerEngine.hpp"
#include "ThreadScheduler.hpp"
#include "MultiCoreScheduler.hpp"
#include "ResourceManager.hpp"
#include "SystemInterface.hpp"
#include "ContextSwitch.hpp"

class OSKernel {
private:

    SchedulerEngine scheduler;
    ThreadScheduler threadScheduler;
    MultiCoreScheduler multiCore;
    ResourceManager resourceManager;
    SystemInterface sysInterface;

    ContextSwitch contextSwitch;   // 🔥 NEW

    AlgoType selectedAlgo;

    TCB* currentThread = nullptr;  // 🔥 Dispatcher tracking

public:

    OSKernel(int cores = 2)
        : multiCore(cores), contextSwitch(1) {}

    // ================= INIT =================
    void init(std::vector<PCB>& processes) {
        selectedAlgo = scheduler.chooseBest(processes);
        std::cout << "Selected Scheduling Algorithm: "
                  << (int)selectedAlgo << "\n";
    }

    // ================= DISPATCHER =================
    void dispatch(TCB*& next,
                  std::vector<std::string>& gantt,
                  int& time) {

        if (currentThread != next) {
            contextSwitch.perform(
                (currentThread ? currentThread->parent : nullptr),
                (next ? next->parent : nullptr),
                gantt,
                time
            );
            currentThread = next;
        }
    }

    // ================= MAIN KERNEL LOOP =================
    void run(std::vector<PCB>& processes) {

        std::cout << "\n=== OS KERNEL START ===\n";

        int time = 0;
        std::vector<std::string> gantt;

        while (true) {

            // ================= 1. TERMINATION CHECK =================
            bool allDone = true;
            for (auto& p : processes)
                if (!p.finished)
                    allDone = false;

            if (allDone)
                break;

            // ================= 2. THREAD ARRIVAL =================
            threadScheduler.addArrivedThreads(processes);

            // ================= 3. HANDLE BLOCKED THREADS =================
            for (auto& p : processes) {
                for (auto& t : p.threads) {

                    if (t.blockType != BlockType::NONE) {

                        SysCallContext ctx;
                        ctx.thread = &t;

                        switch (t.blockType) {

                        case BlockType::MUTEX:
                        case BlockType::SEMAPHORE:
                            sysInterface.invoke(SysCallID::ALLOCATE_RESOURCE, ctx);
                            break;

                        case BlockType::MESSAGE:
                            sysInterface.invoke(SysCallID::RECEIVE, ctx);
                            break;

                        default:
                            break;
                        }
                    }
                }
            }

            // ================= 4. SELECT THREAD =================
            TCB* nextThread = threadScheduler.selectThread();

            if (!nextThread) {
                gantt.push_back("Idle");
                time++;
                std::cout << "Idle CPU\n";
                continue;
            }

            // ================= 5. DISPATCH =================
            dispatch(nextThread, gantt, time);

            StateManager::transition(*nextThread, State::RUNNING);

            // ================= 6. EXECUTION =================
            ExecStatus status = multiCore.scheduleThread(nextThread);

            multiCore.tick(sysInterface);

            threadScheduler.updateWaitingTime(nextThread);

            // ================= 7. HANDLE RESULT =================
            SysCallContext ctx;
            ctx.thread = nextThread;

            switch (status) {

            case ExecStatus::BLOCKED:
                sysInterface.invoke(SysCallID::YIELD, ctx);
                StateManager::transition(*nextThread, State::WAITING);
                break;

            case ExecStatus::FINISHED:
                sysInterface.invoke(SysCallID::TERMINATE, ctx);

                nextThread->state = State::TERMINATED;
                nextThread->Turnaround_Time =
                    nextThread->Waiting_Time + nextThread->Burst_Time;

                resourceManager.releaseAll(*nextThread);
                break;

            case ExecStatus::PREEMPT:
                sysInterface.invoke(SysCallID::YIELD, ctx);
                StateManager::transition(*nextThread, State::READY);
                break;

            case ExecStatus::CONTINUE:
                break;
            }

            // ================= 8. CLEANUP =================
            threadScheduler.cleanup();

            gantt.push_back("T" + std::to_string(nextThread->TID));
            time++;
        }

        // ================= FINAL REPORT =================
        std::cout << "\n=== OS FINISHED ===\n";

        std::cout << "\n--- Gantt Chart ---\n| ";
        for (auto& g : gantt)
            std::cout << g << " | ";
        std::cout << "\n";
    }
};

#endif