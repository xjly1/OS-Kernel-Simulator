#pragma once
#ifndef SYSTEM_INTERFACE_H
#define SYSTEM_INTERFACE_H

#include <iostream>
#include <unordered_map>
#include <functional>

#include "TCB.hpp"
#include "Message.hpp"

// SYSTEM CALL IDS
enum class SysCallID {
    SEND,
    RECEIVE,
    ALLOCATE_RESOURCE,
    RELEASE_RESOURCE,
    TERMINATE,
    YIELD
};

// SYSTEM CALL CONTEXT
struct SysCallContext {
    TCB* thread;
    int arg1 = 0;
    int arg2 = 0;
    std::string strArg;
    Message msg;
};

// SYSTEM CALL INTERFACE
class SystemInterface {
private:

    using SysCallHandler = std::function<bool(SysCallContext&)>;
    std::unordered_map<SysCallID, SysCallHandler> table;

public:

    SystemInterface() {
        registerCalls();
    }

    // REGISTER ALL SYSCALLS
    void registerCalls() {

        table[SysCallID::SEND] = [](SysCallContext& ctx) -> bool {
            if (!ctx.thread) return false;

            ctx.thread->targetTID = ctx.arg1;
            ctx.thread->messageData = ctx.arg2;
            std::cout << "SYS_SEND from T" << ctx.thread->TID << "\n";

            return true;
        };

        table[SysCallID::RECEIVE] = [](SysCallContext& ctx) -> bool {
            std::cout << "SYS_RECEIVE T" << ctx.thread->TID << "\n";
            return true;
        };

        table[SysCallID::ALLOCATE_RESOURCE] = [](SysCallContext& ctx) -> bool {
            std::cout << "RESOURCE REQUEST by T" << ctx.thread->TID << "\n";
            return true;
        };

        table[SysCallID::RELEASE_RESOURCE] = [](SysCallContext& ctx) -> bool {
            std::cout << "RESOURCE RELEASE by T" << ctx.thread->TID << "\n";
            return true;
        };

        table[SysCallID::TERMINATE] = [](SysCallContext& ctx) -> bool {
            ctx.thread->state = State::TERMINATED;
            std::cout << "TERMINATE T" << ctx.thread->TID << "\n";
            return true;
        };

        table[SysCallID::YIELD] = [](SysCallContext& ctx) -> bool {
            std::cout << "YIELD T" << ctx.thread->TID << "\n";
            return true;
        };
    }

    // EXECUTE SYSCALL
    bool invoke(SysCallID id, SysCallContext& ctx) {

        if (table.find(id) == table.end())
            return false;

        return table[id](ctx);
    }
};

#endif