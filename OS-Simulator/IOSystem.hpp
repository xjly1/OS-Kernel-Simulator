#pragma once
#ifndef IOSYSTEM_H
#define IOSYSTEM_H

#include <iostream>
#include <queue>
#include <vector>

#include "PCB.hpp"
#include "StateManager.hpp"

struct IORequest {
    int pid;
};

class IOSystem {
private:
    std::queue<IORequest> deviceQueue;

public:
    // طلب I/O (بدون ioTime)
    void requestIO(std::vector<PCB>& processes, int index) {
        PCB& p = processes[index];

        // تأكيد انه فعلاً محتاج I/O
        if (!p.WaitingForIO)
            return;

        deviceQueue.push({ index });

        std::cout << "P" << p.PID << " requested I/O (auto)\n";
    }

    // تحديث I/O (كل tick)
    void update(std::vector<PCB>& processes) {
        int size = deviceQueue.size();

        for (int i = 0; i < size; i++) {

            IORequest req = deviceQueue.front();
            deviceQueue.pop();
            PCB& p = processes[req.pid];

            // تنفيذ خطوة I/O
            p.executeStep();

            if (p.state == State::READY) {
                std::cout << "P" << p.PID << " finished I/O → READY\n";
            }
            
            else {
                deviceQueue.push(req);
            }
        }
    }

    bool isBusy() const {
        return !deviceQueue.empty();
    }
};

#endif