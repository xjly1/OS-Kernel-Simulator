#pragma once
#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <vector>
#include <map>

#include "TCB.hpp"
#include "SystemInterface.hpp"

enum InstructionType {
    MOV, ADD, SUB, MUL, JMP, PRINT,
    SEND, RECEIVE,
    HALT
};

// EXEC RESULT
enum class ExecStatus {
    CONTINUE,
    PREEMPT,
    BLOCKED,
    FINISHED
};

struct Instruction {
    InstructionType type;
    std::string dest;
    std::string src;
    int value;
    int targetTID;
};

// ALU
class ALU {
    public:
        int add(int a, int b) { return a + b; }
        int sub(int a, int b) { return a - b; }
        int mul(int a, int b) { return a * b; }
    };

// FLAGS
class Flags {
    public:
        bool zero = false;
        bool negative = false;

        void update(int result) {
            zero = (result == 0);
            negative = (result < 0);
        }
};

// MEMORY
class Memory {
    public:
        std::vector<Instruction> program;
};

// REGISTERS
class Registers {
    public:
        std::map<std::string, int> reg;

        Registers() {
            reg["AX"] = 0;
            reg["BX"] = 0;
            reg["CX"] = 0;
            reg["DX"] = 0;
        }
};

// CONTROL UNIT
class ControlUnit {
    public:
        int PC = 0;
        bool running = true;
};

// CPU CORE
class CPU {
    private:
        ALU alu;
        Flags flags;
        Memory memory;
        Registers registers;
        ControlUnit cu;

    public:

        void loadProgram(const std::vector<Instruction>& prog) {
            memory.program = prog;
            cu.PC = 0;
            cu.running = true;
        }

        bool isFinished() const {
            return !cu.running;
        }

        // MAIN STEP (SYSCALL TABLE VERSION)
        ExecStatus step(TCB& t, SystemInterface& sys) {
            if (!cu.running){
                return ExecStatus::FINISHED;
            }

            if (cu.PC >= memory.program.size()) {
                cu.running = false;
                return ExecStatus::FINISHED;
            }

            Instruction inst = memory.program[cu.PC];
            ExecStatus status = ExecStatus::CONTINUE;
            SysCallContext ctx;
            ctx.thread = &t;

            switch (inst.type) {

            case MOV:
                registers.reg[inst.dest] = inst.value;
                break;

            case ADD: {
                int r = alu.add(registers.reg[inst.dest], registers.reg[inst.src]);
                registers.reg[inst.dest] = r;
                flags.update(r);
                break;
            }

            case SUB: {
                int r = alu.sub(registers.reg[inst.dest], registers.reg[inst.src]);
                registers.reg[inst.dest] = r;
                flags.update(r);
                break;
            }

            case MUL: {
                int r = alu.mul(registers.reg[inst.dest], registers.reg[inst.src]);
                registers.reg[inst.dest] = r;
                flags.update(r);
                break;
            }

            case JMP:
                cu.PC = inst.value;
                return ExecStatus::CONTINUE;

            case PRINT:
                std::cout << "T" << t.TID << " -> "
                        << inst.dest << " = "
                        << registers.reg[inst.dest] << "\n";
                break;

            // IPC (SYSTEM CALLS NOW)
            case SEND: {
                t.targetTID = inst.targetTID;
                t.messageData = registers.reg[inst.dest];
                ctx.arg1 = inst.targetTID;
                ctx.arg2 = registers.reg[inst.dest];
                sys.invoke(SysCallID::SEND, ctx);

                if (t.blockType != BlockType::NONE){
                    return ExecStatus::BLOCKED;
                }

                break;
            }

            case RECEIVE: {
                Message msg;

                if (!sys.invoke(SysCallID::RECEIVE, ctx)){
                    return ExecStatus::BLOCKED;
                }

                registers.reg[inst.dest] = msg.data;
                break;
            }

            case HALT:
                cu.running = false;
                return ExecStatus::FINISHED;
            }

            cu.PC++;

            // RR HINT
            status = ExecStatus::PREEMPT;
            return status;
        }
};

#endif