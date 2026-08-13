#pragma once
#ifndef SYSTEM_CALL_H
#define SYSTEM_CALL_H

#include <iostream>

#include "Mailbox.hpp"
#include "SharedMemory.hpp"
#include "TCB.hpp"

// SYSTEM CALL INTERFACE

class SystemCall {
private:
    Mailbox& mailbox;
    SharedMemory& sharedMem;

public:

    SystemCall(Mailbox& m, SharedMemory& s) : mailbox(m), sharedMem(s) {}

    // SEND
    bool sys_send(TCB& sender) {

        if (sender.targetTID < 0) {
            std::cout << "SYS_ERROR: Invalid receiver TID\n";
            return false;
        }

        bool ok = mailbox.send(sender, sender.targetTID, sender.messageData);

        if (!ok) {
            std::cout << "SYS_SEND FAILED (MAILBOX FULL or BLOCKED)\n";
        }

        return ok;
    }

    // RECEIVE
    bool sys_receive(TCB& receiver, Message& msg) {

        bool ok = mailbox.receive(receiver, msg);

        if (!ok) {
            // process will be blocked by scheduler
            return false;
        }

        return true;
    }

    // SHARED MEMORY WRITE
    bool sys_write(TCB& t, int key, int value) {

        if (key < 0) {
            std::cout << "SYS_ERROR: invalid memory key\n";
            return false;
        }

        sharedMem.write(t, key, value);
        return true;
    }

    // SHARED MEMORY READ
    int sys_read(TCB& t, int key) {

        if (key < 0) {
            std::cout << "SYS_ERROR: invalid memory key\n";
            return -1;
        }

        return sharedMem.read(t, key);
    }
};

#endif