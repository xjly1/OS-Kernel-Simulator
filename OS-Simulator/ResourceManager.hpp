#pragma once
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <iostream>
#include <vector>
#include <map>
#include <queue>

#include "TCB.hpp"

// RESOURCE MANAGER

class ResourceManager {

private:

    // Available instances لكل resource
    std::map<int, int> available;

    // منو ماسك شنو
    std::map<int, std::vector<int>> allocation;

    // طلبات pending
    std::map<int, std::queue<int>> waitingQueue;

public:

    // INIT RESOURCES
    void addResource(int resourceId, int count) {
        available[resourceId] = count;
    }

    // REQUEST RESOURCE
    bool requestResource(TCB& t, int resourceId) {

        // إذا متوفر
        if (available[resourceId] > 0) {

            available[resourceId]--;
            allocation[t.TID].push_back(resourceId);
            std::cout << "T" << t.TID << " acquired R" << resourceId << "\n";
            return true;
        }

        // إذا مو متوفر → يدخل انتظار
        waitingQueue[resourceId].push(t.TID);
        t.blockType = BlockType::MUTEX;
        std::cout << "T" << t.TID << " BLOCKED on R" << resourceId << "\n";
        return false;
    }

    // RELEASE RESOURCE
    void releaseResource(TCB& t, int resourceId) {

        auto& list = allocation[t.TID];

        for (auto it = list.begin(); it != list.end(); ++it) {
            if (*it == resourceId) {
                list.erase(it);
                break;
            }
        }

        available[resourceId]++;

        std::cout << "T" << t.TID << " released R" << resourceId << "\n";

        // wake up next waiting thread
        if (!waitingQueue[resourceId].empty()) {

            int nextTID = waitingQueue[resourceId].front();
            waitingQueue[resourceId].pop();
            available[resourceId]--;

            std::cout << "R" << resourceId
                      << " reassigned to T"
                      << nextTID << "\n";
        }
    }

    // CLEANUP ON TERMINATION
    void releaseAll(TCB& t) {

        auto& list = allocation[t.TID];

        for (int res : list) {
            available[res]++;
        }

        list.clear();
    }

    // DEADLOCK CHECK (SIMPLE)
    bool detectDeadlock() {

        for (auto& q : waitingQueue) {
            if (!q.second.empty()) {
                std::cout << "⚠ Potential Deadlock on Resource "
                          << q.first << "\n";
                return true;
            }
        }

        return false;
    }

    // DEBUG
    void printStatus() {

        std::cout << "\n=== RESOURCE STATUS ===\n";

        for (auto& a : available) {
            std::cout << "R" << a.first
                      << " Available: " << a.second << "\n";
        }

        std::cout << "=======================\n";
    }
};

#endif