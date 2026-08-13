#include <iostream>
#include <queue>
#include <vector>

#include "PCB.hpp"
#include "IOSystem.hpp"
#include "StateManager.hpp"

void updateWaitingTime(std::vector<PCB>& processes, int runningPID) {
    for (auto& p : processes)
        if (p.state == State::READY && p.PID != runningPID)
            p.Waiting_Time++;
}

void pushReadyFromIO(std::vector<PCB>& processes, std::queue<int>& q) {
    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].state == State::READY)
            q.push(i);
    }
}

void FCFS(std::vector<PCB>& processes) {

    IOSystem io;

    int time = 0, completed = 0, n = processes.size();

    std::queue<int> q;
    std::vector<bool> inQueue(n, false);

    while (completed < n) {
        // Arrival
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && processes[i].Arrival_Time <= time) {
                q.push(i);
                inQueue[i] = true;
                StateManager::transition(processes[i], State::READY);
            }
        }

        io.update(processes);
        pushReadyFromIO(processes, q);

        if (q.empty()) {
            updateWaitingTime(processes, -1);
            time++;
            continue;
        }

        int i = q.front(); q.pop();
        
        PCB& p = processes[i];
        StateManager::transition(p, State::RUNNING);

        while (true) {
            p.executeStep();
            time++;
            updateWaitingTime(processes, p.PID);
            io.update(processes);
            pushReadyFromIO(processes, q);

            if (p.state == State::WAITING) {
                io.requestIO(processes, i);
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