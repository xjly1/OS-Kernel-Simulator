#pragma once
#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <iostream>
#include <string>

//STATE
enum class State {
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

//PCB
struct PCB {
    int PID;
    int Arrival_Time;
    int Burst_Time;
    int Remaining_Time;
    int Priority;
    int Waiting_Time = 0;
    int Turnaround_Time = 0;
    State state;

    PCB(int id, int at, int bt, int pr)
        : PID(id),
        Arrival_Time(at),
        Burst_Time(bt),
        Remaining_Time(bt),
        Priority(pr),
        state(State::NEW) {
    }
};

//StateManager
class StateManager {
    public:

        // تحويل الحالة مع تحقق
        static bool transition(PCB& p, State newState) {
            
            if (!isValidTransition(p.state, newState)) {
                std::cout << "Invalid Transition: "
                    << stateToString(p.state)
                    << " → " << stateToString(newState)
                    << " (PID " << p.PID << ")\n";
                return false;
            }

            std::cout << " PID " << p.PID << ": "
                << stateToString(p.state)
                << " → " << stateToString(newState) << std::endl;

            p.state = newState;
            return true;
        }

        // تحقق من صحة الانتقال
        static bool isValidTransition(State from, State to) {

            switch (from) {
            case State::NEW:
                return to == State::READY;

            case State::READY:
                return to == State::RUNNING;

            case State::RUNNING:
                return to == State::READY ||
                    to == State::WAITING ||
                    to == State::TERMINATED;

            case State::WAITING:
                return to == State::READY;

            case State::TERMINATED:
                return false;
            }

            return false;
        }

        // تحويل state إلى string
        static std::string stateToString(State s) {
            switch (s) {
            case State::NEW: return "NEW";
            case State::READY: return "READY";
            case State::RUNNING: return "RUNNING";
            case State::WAITING: return "WAITING";
            case State::TERMINATED: return "TERMINATED";
            }
            return "UNKNOWN";
        }
};

#endif