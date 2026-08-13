#include <iostream>
#include <vector>
#include <climits>

#include "PCB.hpp"
#include "IOSystem.hpp"
#include "StateManager.hpp"

void updateWaitingTime(std::vector<PCB>& processes, int runningPID) {
    for (auto& p : processes) {
        if (p.state == State::READY && p.PID != runningPID) {
            p.Waiting_Time++;
        }
    }
}

void pushReadyFromIO(std::vector<PCB>& processes) {
    for (auto& p : processes) {
        if (p.state == State::WAITING && !p.WaitingForIO) {
            StateManager::transition(p, State::READY);
        }
    }
}

void SJF(std::vector<PCB>& processes) {
    IOSystem io;
    int time = 0, completed = 0, n = processes.size();

    while (completed < n) {
        io.update(processes);
        pushReadyFromIO(processes);
        int idx = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].Arrival_Time <= time &&
                processes[i].state == State::READY &&
                processes[i].Remaining_Time > 0) {

                if (processes[i].Remaining_Time < minBurst ||
                    (processes[i].Remaining_Time == minBurst &&
                     (idx == -1 || processes[i].Priority < processes[idx].Priority))) {

                    minBurst = processes[i].Remaining_Time;
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
            pushReadyFromIO(processes);

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

        // Context Switch
        updateWaitingTime(processes, -1);
        time++;
    }
}

int main() {

    return 0;
}