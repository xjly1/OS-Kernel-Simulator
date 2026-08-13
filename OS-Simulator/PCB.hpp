#pragma once
#ifndef PCB_H
#define PCB_H

#include <iostream>
#include <vector>

#include "StateManager.hpp"
#include "Registers.hpp"
#include "TCB.hpp"

class PCB {
public:
    int PID;
    int Arrival_Time;
    int Priority;

    // REAL-TIME SUPPORT
    int deadline = -1;
    int period = -1;
    bool isRealTime = false;
    int Waiting_Time = 0;
    int Turnaround_Time = 0;

    // CPU/IO BURSTS
    std::vector<int> cpuBursts;
    std::vector<int> ioBursts;
    int cpuIndex = 0;
    int ioIndex = 0;
    int remainingTime = 0;
    bool isCpuPhase = true;
    bool finished = false;
    int ProgramCounter = 0;
    Registers registers;
    bool WaitingForIO = false;
    std::vector<TCB> threads;
    State state;

    PCB(int id, int at,
        std::vector<int> cpu,
        std::vector<int> io,
        int pr)
        : PID(id),
          Arrival_Time(at),
          cpuBursts(cpu),
          ioBursts(io),
          Priority(pr),
          registers(8),
          state(State::NEW)
    {
        if (!cpuBursts.empty())
            remainingTime = cpuBursts[0];
    }

    // CPU/IO CYCLE
    void executeStep() {

        if (finished) return;

        if (remainingTime > 0) {
            remainingTime--;
            ProgramCounter++;
        }

        // CPU done
        if (remainingTime == 0 && isCpuPhase) {

            cpuIndex++;

            if (cpuIndex < cpuBursts.size()) {
                isCpuPhase = false;
                WaitingForIO = true;
                state = State::WAITING;

                if (ioIndex < ioBursts.size())
                    remainingTime = ioBursts[ioIndex];
                else
                    remainingTime = cpuBursts[cpuIndex];
            }
            else {
                finished = true;
                state = State::TERMINATED;
            }
        }

        // IO done
        else if (remainingTime == 0 && !isCpuPhase) {

            ioIndex++;
            isCpuPhase = true;
            WaitingForIO = false;

            if (cpuIndex < cpuBursts.size()) {
                remainingTime = cpuBursts[cpuIndex];
                state = State::READY;
            }
            else {
                finished = true;
                state = State::TERMINATED;
            }
        }
    }

    void createThread(int tid, int at, int bt, int pr) {
        threads.emplace_back(tid, PID, at, bt, pr);
    }

    void print() const {
        std::cout << "P" << PID;

        if (isRealTime)
            std::cout << " [RT D:" << deadline << "]";

        std::cout << " WT:" << Waiting_Time
                  << " TAT:" << Turnaround_Time
                  << " State:" << StateManager::stateToString(state)
                  << "\n";

        for (auto& t : threads)
            t.print();
    }
};

#endif