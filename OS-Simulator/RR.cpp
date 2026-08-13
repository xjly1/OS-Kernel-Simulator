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

void RoundRobin(std::vector<PCB>& processes, int quantum) {
    IOSystem io;
    int time = 0, completed = 0, n = processes.size();
    std::queue<int> q;
    std::vector<bool> inQueue(n, false);

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && processes[i].Arrival_Time <= time) {
                q.push(i);
                inQueue[i] = true;
                StateManager::transition(processes[i], State::READY);
            }
        }

        io.update(processes);

        if (q.empty()) {
            updateWaitingTime(processes, -1);
            time++;
            continue;
        }

        int i = q.front(); q.pop();
        PCB& p = processes[i];
        StateManager::transition(p, State::RUNNING);
        int qtime = 0;

        while (qtime < quantum) {
            p.executeStep();
            time++;
            qtime++;
            updateWaitingTime(processes, p.PID);
            io.update(processes);

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

        if (p.state == State::RUNNING) {
            StateManager::transition(p, State::READY);
            q.push(i);
        }

        updateWaitingTime(processes, -1);
        time++;
    }
}

int main() {
    return 0;
}