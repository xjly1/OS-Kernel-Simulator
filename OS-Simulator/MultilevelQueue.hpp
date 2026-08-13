#pragma once
#ifndef MULTILEVELQUEUE_H
#define MULTILEVELQUEUE_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include "PCB.hpp"
#include "StateManager.hpp"

class MultilevelQueue {
private:
    int time = 0;
    std::queue<int> Q0; // RR
    std::vector<int> Q1; // SJF
    std::queue<int> Q2; // FCFS
    int quantum = 3;

public:

    // توزيع العمليات على الـ Queues حسب Priority
    void assignQueues(std::vector<PCB>& p) {
        for (int i = 0; i < p.size(); i++) {

            if (p[i].Priority == 0)
                Q0.push(i);
            else if (p[i].Priority == 1)
                Q1.push_back(i);
            else
                Q2.push(i);
        }
    }

    float run(std::vector<PCB> processes) {
        int n = processes.size();
        int completed = 0;
        std::vector<std::string> gantt;
        assignQueues(processes);

        // كل العمليات READY
        for (auto& p : processes)
            StateManager::transition(p, State::READY);

        std::cout << "\n=== Multilevel Queue Scheduling ===\n";

        while (completed < n) {

            // Q0 → Round Robin
            if (!Q0.empty()) {

                int idx = Q0.front();
                Q0.pop();
                PCB& p = processes[idx];

                if (p.state == State::TERMINATED)
                    continue;

                StateManager::transition(p, State::RUNNING);
                int exec = std::min(quantum, p.Remaining_Time);

                for (int i = 0; i < exec; i++) {
                    gantt.push_back("P" + std::to_string(p.PID));
                    time++;
                }

                p.Remaining_Time -= exec;

                if (p.Remaining_Time == 0) {

                    completed++;
                    StateManager::transition(p, State::TERMINATED);
                    p.Turnaround_Time = time - p.Arrival_Time;
                    p.Waiting_Time = p.Turnaround_Time - p.Burst_Time;
                }

                else {
                    StateManager::transition(p, State::READY);
                    Q0.push(idx);
                }

                continue;
            }

            // Q1 → SJF
            if (!Q1.empty()) {

                // اختيار shortest job
                int best = -1;
                int min_bt = INT_MAX;

                for (int i = 0; i < Q1.size(); i++) {
                    int idx = Q1[i];

                    if (processes[idx].Remaining_Time < min_bt &&
                        processes[idx].state != State::TERMINATED) {
                        min_bt = processes[idx].Remaining_Time;
                        best = i;
                    }
                }

                if (best == -1) {
                    Q1.clear();
                    continue;
                }

                int idx = Q1[best];
                Q1.erase(Q1.begin() + best);
                PCB& p = processes[idx];
                StateManager::transition(p, State::RUNNING);
                int exec = p.Remaining_Time;

                for (int i = 0; i < exec; i++) {
                    gantt.push_back("P" + std::to_string(p.PID));
                    time++;
                }

                p.Remaining_Time = 0;
                completed++;
                StateManager::transition(p, State::TERMINATED);
                p.Turnaround_Time = time - p.Arrival_Time;
                p.Waiting_Time = p.Turnaround_Time - p.Burst_Time;
                continue;
            }

            // Q2 → FCFS
            if (!Q2.empty()) {

                int idx = Q2.front();
                Q2.pop();
                PCB& p = processes[idx];

                if (p.state == State::TERMINATED)
                    continue;

                StateManager::transition(p, State::RUNNING);
                int exec = p.Remaining_Time;

                for (int i = 0; i < exec; i++) {
                    gantt.push_back("P" + std::to_string(p.PID));
                    time++;
                }

                p.Remaining_Time = 0;
                completed++;
                StateManager::transition(p, State::TERMINATED);
                p.Turnaround_Time = time - p.Arrival_Time;
                p.Waiting_Time = p.Turnaround_Time - p.Burst_Time;

                continue;
            }

            // Idle
            gantt.push_back("Idle");
            time++;
        }

        float avgWT = 0;

        for (auto& p : processes)
            avgWT += p.Waiting_Time;

        avgWT /= n;

        // Gantt
        std::cout << "\n--- Gantt Chart ---\n| ";
        for (auto& g : gantt)
            std::cout << g << " | ";
        std::cout << "\n";

        std::cout << "Multilevel Queue Avg WT = " << avgWT << "\n";

        return avgWT;
    }
};

#endif