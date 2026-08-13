#pragma once
#ifndef MESSAGE_SYSTEM_H
#define MESSAGE_SYSTEM_H

#include "TCB.hpp"
#include "StateManager.hpp"
#include "Message.hpp"

class MessageSystem {
    public:
        // SEND (bounded)
        static bool send(TCB& sender, TCB& receiver, const std::string& msg) {
            // إذا queue ممتلئة → block sender
            if (receiver.isQueueFull()) {
                sender.blockType = BlockType::IPC;
                sender.blockedOnSend = true;
                StateManager::transition(sender, State::WAITING);
                return false;
            }

            Message m{sender.TID, receiver.TID, msg};
            receiver.pushMessage(m);

            // wake receiver إذا كان ينتظر
            if (receiver.blockedOnReceive) {
                receiver.blockedOnReceive = false;
                receiver.blockType = BlockType::NONE;
                StateManager::transition(receiver, State::READY);
            }

            return true;
        }

        // RECEIVE
        static bool receive(TCB& receiver, Message& out) {
            // إذا ماكو رسالة → block
            if (!receiver.hasMessage()) {
                receiver.blockType = BlockType::IPC;
                receiver.blockedOnReceive = true;
                StateManager::transition(receiver, State::WAITING);
                return false;
            }

            out = receiver.popMessage();
            return true;
        }
};

#endif