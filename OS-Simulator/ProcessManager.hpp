#pragma once
#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <vector>
#include <iostream>

#include "PCB.hpp"

class ProcessManager {
private:
    std::vector<PCB*> processes;

public:
    void addProcess(PCB* p) {
        processes.push_back(p);
    }

    std::vector<PCB*>& getProcesses() {
        return processes;
    }

    void printAll() {
        std::cout << "\n--- Process List ---\n";
        for (auto p : processes) {
            p->print();
        }
    }
};

#endif