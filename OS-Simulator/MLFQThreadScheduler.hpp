#pragma once
#ifndef MLFQ_H
#define MLFQ_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#include "PCB.hpp"
#include "StateManager.hpp"
#include "IOSystem.hpp"

class MLFQ {
private:
    int time = 0;
    int context_switch = 1;
    std::vector<std::queue<int>> queues;
    std::vector<int> quantum;

public:
    MLFQ(int levels) {
        queues.resize(levels);
        quantum.resize(levels);
        quantum[0] = 4;
        quantum[1] = 8;
        quantum[2] = -1; // FCFS
    }

    // Waiting Time دقيق
    void updateWaitingTime(std::vector<PCB>& processes, int runningPID) {
        for (auto& p : processes) {
            if (p.state == State::READY && p.PID != runningPID)
                p.Waiting_Time++;
        }
    }

    // إدخال العمليات الجاهزة بدون تكرار
    void pushReadyProcesses(std::vector<PCB>& processes, std::vector<bool>& inQueue) {
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].state == State::READY && !inQueue[i]) {
                queues[0].push(i);
                inQueue[i] = true;
            }
        }
    }

    // Arrival فقط
    void handleArrival(std::vector<PCB>& processes, std::vector<bool>& inQueue) {
        for (int i = 0; i < processes.size(); i++) {
            if (!inQueue[i] &&
                processes[i].Arrival_Time == time) {
                StateManager::transition(processes[i], State::READY);
                queues[0].push(i);
                inQueue[i] = true;
            }
        }
    }

    // Aging حقيقي بدون duplication
    void aging(std::vector<PCB>& processes) {
        for (int lvl = 1; lvl < queues.size(); lvl++) {
            int size = queues[lvl].size();

            for (int i = 0; i < size; i++) {
                int idx = queues[lvl].front();
                queues[lvl].pop();
                PCB& p = processes[idx];

                if (p.state == State::READY && p.Waiting_Time > 10) {
                    int newLevel = lvl - 1;
                    std::cout << "Aging: Promote P" << p.PID << " → Q" << newLevel << "\n";
                    queues[newLevel].push(idx);
                }
                else {
                    queues[lvl].push(idx);
                }
            }
        }
    }

    // اختيار أول Queue فعالة
    int getActiveQueue() {
        for (int i = 0; i < queues.size(); i++) {
            if (!queues[i].empty())
                return i;
        }
        return -1;
    }

    float run(std::vector<PCB> processes) {
        IOSystem io;
        int n = processes.size();
        int completed = 0;
        std::vector<std::string> gantt;
        std::vector<bool> inQueue(n, false);
        std::cout << "\n=== MLFQ (Improved Real OS) ===\n";

        while (completed < n) {
            // Arrival
            handleArrival(processes, inQueue);

            // I/O Update
            io.update(processes);

            // رجوع READY
            pushReadyProcesses(processes, inQueue);

            // Aging
            aging(processes);

            int level = getActiveQueue();

            // Idle
            if (level == -1) {
                gantt.push_back("Idle");
                updateWaitingTime(processes, -1);
                time++;
                continue;
            }

            int idx = queues[level].front();
            queues[level].pop();
            inQueue[idx] = false;
            PCB& p = processes[idx];
            StateManager::transition(p, State::RUNNING);
            int qtime = 0;
            int qlimit = quantum[level];

            while (true) {
                p.executeStep();
                time++;
                qtime++;
                gantt.push_back("P" + std::to_string(p.PID));
                updateWaitingTime(processes, p.PID);
                io.update(processes);
                pushReadyProcesses(processes, inQueue);

                // I/O
                if (p.state == State::WAITING) {
                    io.requestIO(processes, idx);
                    break;
                }

                // انتهى
                if (p.state == State::TERMINATED) {
                    completed++;
                    p.Turnaround_Time = time - p.Arrival_Time;
                    break;
                }

                // Quantum
                if (qlimit != -1 && qtime >= qlimit) {
                    StateManager::transition(p, State::READY);
                    int newLevel = std::min(level + 1, (int)queues.size() - 1);
                    queues[newLevel].push(idx);
                    inQueue[idx] = true;
                    break;
                }

                // FCFS queue
                if (qlimit == -1)
                    continue;
            }

            // Context Switch حقيقي
            if (completed < n) {
                gantt.push_back("CS");

                for (int i = 0; i < context_switch; i++) {
                    updateWaitingTime(processes, -1);
                    time++;
                }
            }
        }

        float avgWT = 0;

        std::cout << "\nPID\tWT\tTAT\n";
        for (auto& p : processes) {
            std::cout << p.PID << "\t"
                      << p.Waiting_Time << "\t"
                      << p.Turnaround_Time << "\n";
            avgWT += p.Waiting_Time;
        }

        avgWT /= n;

        std::cout << "\n--- Gantt Chart ---\n| ";
        for (auto& g : gantt)
            std::cout << g << " | ";
        std::cout << "\n";

        std::cout << "MLFQ Avg WT = " << avgWT << "\n";

        return avgWT;
    }
};

#endif