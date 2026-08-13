#pragma once
#ifndef THREAD_SCHEDULER_H
#define THREAD_SCHEDULER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#include "PCB.hpp"
#include "TCB.hpp"
#include "StateManager.hpp"
#include "ResourceManager.hpp"
#include "SystemCall.hpp"

class ThreadScheduler {
private:
    int time = 0;
    std::vector<TCB*> readyQueue;

public:
    ResourceManager resourceManager;
    SystemCall* sys = nullptr;

    // inject SystemCall from Kernel
    void bindSystemCall(SystemCall& s) {
        sys = &s;
    }

    void pushIfNotExists(TCB* t) {
        if (!t) return;

        for (auto* x : readyQueue)
            if (x == t) return;

        readyQueue.push_back(t);
    }

    void addArrivedThreads(std::vector<PCB>& processes) {

        for (auto& p : processes) {

            if (p.state == State::TERMINATED)
                continue;

            if (p.finished)
                continue;

            for (auto& t : p.threads) {

                if (t.Arrival_Time == time &&
                    t.state != State::TERMINATED) {

                    StateManager::transition(t, State::READY);
                    pushIfNotExists(&t);
                }
            }
        }
    }

    void updateWaitingTime(TCB* running) {
        for (auto* t : readyQueue) {
            if (t != running && t->state == State::READY)
                t->Waiting_Time++;
        }
    }

    TCB* selectThread() {

        TCB* best = nullptr;
        int bestPr = INT_MAX;
        int bestRem = INT_MAX;

        for (auto* t : readyQueue) {

            if (t->state != State::READY ||
                t->blockType != BlockType::NONE)
                continue;

            if (t->Priority < bestPr ||
               (t->Priority == bestPr &&
                t->Remaining_Time < bestRem)) {

                best = t;
                bestPr = t->Priority;
                bestRem = t->Remaining_Time;
            }
        }

        return best;
    }

    void cleanup() {
        readyQueue.erase(
            std::remove_if(readyQueue.begin(), readyQueue.end(),
                [](TCB* t) {
                    return t->state == State::TERMINATED;
                }),
            readyQueue.end());
    }

    bool allFinished(std::vector<PCB>& processes) {
        for (auto& p : processes)
            if (!p.finished)
                return false;

        return true;
    }

    // MAIN LOOP
    void run(std::vector<PCB>& processes) {

        std::cout << "THREAD OS (FINAL SYSCALL-INTEGRATED)\n";

        while (!allFinished(processes)) {

            addArrivedThreads(processes);
            cleanup();

            TCB* current = selectThread();

            if (!current) {
                std::cout << time << " Idle\n";
                time++;
                continue;
            }

            StateManager::transition(*current, State::RUNNING);

            // SYSCALL-BASED RESOURCE CHECK
            if (sys != nullptr) {

                if (!resourceManager.requestResource(*current, 1)) {

                    // نفس فكرة sys_receive / sys_send
                    sys->sys_receive(*current, *(new Message()));

                    current->state = State::WAITING;

                    std::cout << "T" << current->TID
                              << " blocked via SYS_CALL (resource)\n";

                    time++;
                    continue;
                }
            }

            // CPU EXECUTION
            current->cpu.step(*current, *sys);
            updateWaitingTime(current);
            time++;

            // FINISH
            if (current->cpu.isFinished()) {

                current->state = State::TERMINATED;
                current->Turnaround_Time = time - current->Arrival_Time;
                resourceManager.releaseAll(*current);
            }
            else {
                StateManager::transition(*current, State::READY);
            }
        }
    }
};

#endif