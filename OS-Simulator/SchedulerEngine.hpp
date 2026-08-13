#pragma once
#ifndef SCHEDULER_ENGINE_H
#define SCHEDULER_ENGINE_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "PCB.hpp"

enum class AlgoType { FCFS, SJF, RR, EDF };

struct Result {
    float avgWT;
    float avgTAT;
};

class SchedulerEngine {
public:

    //store selected algorithm globally
    static AlgoType selectedAlgorithm;

    static Result calc(std::vector<PCB>& p) {
        float wt = 0, tat = 0;

        for (auto& x : p) {
            wt += x.Waiting_Time;
            tat += x.Turnaround_Time;
        }

        if (p.empty()) return {0,0};

        return { wt / p.size(), tat / p.size() };
    }

    // EDF
    static bool EDFCompare(const PCB& a, const PCB& b) {
        if (a.isRealTime && b.isRealTime)
            return a.deadline < b.deadline;

        if (a.isRealTime) return true;
        if (b.isRealTime) return false;
        return a.Priority < b.Priority;
    }

    static void applyEDF(std::vector<PCB>& p) {
        std::sort(p.begin(), p.end(), EDFCompare);
    }

    static AlgoType chooseBest(std::vector<PCB> p) {

        auto a = p, b = p, c = p, d = p;

        // simulate (placeholder)
        applyEDF(d);

        Result r1 = calc(a);
        Result r2 = calc(b);
        Result r3 = calc(c);
        Result r4 = calc(d);

        std::cout << "FCFS " << r1.avgWT << "\n";
        std::cout << "SJF  " << r2.avgWT << "\n";
        std::cout << "RR   " << r3.avgWT << "\n";
        std::cout << "EDF  " << r4.avgWT << "\n";

        AlgoType best = AlgoType::FCFS;
        float minv = r1.avgWT;

        if (r2.avgWT < minv) { minv = r2.avgWT; best = AlgoType::SJF; }
        if (r3.avgWT < minv) { minv = r3.avgWT; best = AlgoType::RR; }
        if (r4.avgWT < minv) { best = AlgoType::EDF; }

        // store decision
        selectedAlgorithm = best;

        return best;
    }
};

#endif