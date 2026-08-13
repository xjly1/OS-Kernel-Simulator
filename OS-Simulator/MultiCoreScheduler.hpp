#pragma once
#ifndef MULTICORE_SCHEDULER_H
#define MULTICORE_SCHEDULER_H

#include <vector>
#include <climits>
#include <iostream>

#include "PCB.hpp"
#include "TCB.hpp"
#include "CPU.hpp"

// Multi-Core Scheduler
class MultiCoreScheduler {
private:

    // كل CPU يمثل core مستقل
    std::vector<CPU> cores;

public:

    // ================= CONSTRUCTOR
    MultiCoreScheduler(int coreCount = 2) {
        for (int i = 0; i < coreCount; i++) {
            cores.emplace_back(i);
        }
    }

    // ================= GET LEAST LOADED CORE =================
    CPU* getBestCore() {

        CPU* best = nullptr;
        int minLoad = INT_MAX;

        for (auto& core : cores) {

            int load = 0;

            if (!core.isIdle())
                load = 1; // simplified load model (stable + fast)

            if (load < minLoad) {
                minLoad = load;
                best = &core;
            }
        }

        return best;
    }

    // ================= SCHEDULE PROCESS =================
    void scheduleProcess(PCB* p) {

        if (!p || p->finished)
            return;

        CPU* core = getBestCore();

        if (core) {
            core->assign(p);

            std::cout << "[CORE " << core->id
                      << "] Running Process P"
                      << p->PID << "\n";
        }
    }

    // ================= SCHEDULE THREAD =================
    void scheduleThread(TCB* t) {

        if (!t || t->state == State::TERMINATED)
            return;

        CPU* core = getBestCore();

        if (core) {
            core->assign(t);

            std::cout << "[CORE " << core->id
                      << "] Running Thread T"
                      << t->TID << "\n";
        }
    }

    // ================= RELEASE ALL CORES =================
    void releaseAll() {
        for (auto& core : cores) {
            core.release();
        }
    }

    // ================= STATUS DEBUG =================
    void printStatus() const {

        std::cout << "\n=== MULTI-CORE STATUS ===\n";

        for (const auto& core : cores) {

            std::cout << "Core " << core.id << " : ";

            if (core.isIdle())
                std::cout << "IDLE\n";
            else if (core.runningTCB)
                std::cout << "Thread T" << core.runningTCB->TID << "\n";
            else if (core.runningPCB)
                std::cout << "Process P" << core.runningPCB->PID << "\n";
        }

        std::cout << "=========================\n";
    }

    // ================= OPTIONAL: STEP EXECUTION =================
    void tick(SystemCall& sys) {

        for (auto& core : cores) {

            if (!core.isIdle()) {

                // Thread execution priority first
                if (core.runningTCB) {

                    core.runningTCB->cpu.step(*core.runningTCB, sys);

                    if (core.runningTCB->cpu.isFinished()) {
                        core.runningTCB->state = State::TERMINATED;
                        core.release();
                    }
                }

                // Process execution fallback
                else if (core.runningPCB) {

                    core.runningPCB->executeStep();

                    if (core.runningPCB->finished) {
                        core.release();
                    }
                }
            }
        }
    }
};

#endif