#pragma once
#ifndef REGISTERS_H
#define REGISTERS_H

#include <vector>

class Registers {
    public:
        std::vector<int> regs;

        Registers(int size = 8) {
        regs.resize(size, 0);
        }

        void set(int index, int value) {
            if (index >= 0 && index < regs.size())
                regs[index] = value;
        }

        int get(int index) const {
            if (index >= 0 && index < regs.size())
                return regs[index];
            return -1;
        }
};

#endif