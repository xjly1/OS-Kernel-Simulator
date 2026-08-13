#include <iostream>
#include <vector>
#include <climits>

#include "PCB.hpp"
#include "IOSystem.hpp"
#include "StateManager.hpp"

void updateWaitingTime(std::vector<PCB>& processes, int runningPID) {
    for (auto& p : processes)
        if (p.state == State::READY && p.PID != runningPID)
            p.Waiting_Time++;
}

void PriorityScheduling(std::vector<PCB>& processes) {

    IOSystem io;
    int time = 0, completed = 0, n = processes.size();

    while (completed < n) {

        io.update(processes);
        int idx = -1;
        int best = INT_MAX;

        for (int i = 0; i < n; i++) {

            if (processes[i].Arrival_Time <= time && processes[i].state == State::READY) {
                if (processes[i].Priority < best) {
                    best = processes[i].Priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            updateWaitingTime(processes, -1);
            time++;
            continue;
        }

        PCB& p = processes[idx];
        StateManager::transition(p, State::RUNNING);

        while (true) {

            p.executeStep();
            time++;
            updateWaitingTime(processes, p.PID);
            io.update(processes);

            if (p.state == State::WAITING) {
                io.requestIO(processes, idx);
                break;
            }

            if (p.state == State::TERMINATED) {
                completed++;
                p.Turnaround_Time = time - p.Arrival_Time;
                break;
            }
        }

        // Aging حقيقي
        for (auto& proc : processes)
            if (proc.state == State::READY && proc.Priority > 0)
                proc.Priority--;
    }
}

int main() {
    
    return 0;
}