#pragma once
#ifndef CONTEXT_SWITCH_H
#define CONTEXT_SWITCH_H

#include <iostream>
#include <vector>

#include "PCB.hpp"

// يمثل عملية Context Switch حقيقية
class ContextSwitch {
    private:
        int switchCost; // الوقت المستغرق

    public:
        ContextSwitch(int cost = 1) : switchCost(cost) {}

        int getCost() const {
            return switchCost;
        }

        // حفظ حالة العملية
        void saveState(PCB& p) {
            // نحاكي حفظ الـ registers + PC
            // (حالياً simulation فقط)
            std::cout << " Saving state of P" << p.PID << "\n";
        }

        // استرجاع حالة العملية
        void loadState(PCB& p) {
            std::cout << " Loading state of P" << p.PID << "\n";
        }

        // تنفيذ Context Switch
        int perform(PCB* current, PCB* next, std::vector<std::string>& gantt, int& time) {

            if (current != nullptr) {
                saveState(*current);
            }

            if (next != nullptr) {
                loadState(*next);
            }

            // نضيف CS للـ Gantt
            for (int i = 0; i < switchCost; i++) {
                gantt.push_back("CS");
                time++;
            }

            std::cout << " Context Switch (+" << switchCost << ")\n";
            return switchCost;
        }
};

#endif