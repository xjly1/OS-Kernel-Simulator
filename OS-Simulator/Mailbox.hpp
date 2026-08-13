#pragma once
#ifndef MAILBOX_H
#define MAILBOX_H

#include <queue>
#include <unordered_map>

#include "Message.hpp"
#include "TCB.hpp"
#include "StateManager.hpp"

class Mailbox {
    private:
        // Kernel-managed queues (TID → messages)
        std::unordered_map<int, std::queue<Message>> queues;

        // Threads المنتظرة receive
        std::unordered_map<int, TCB*> waitingThreads;

    public:
        // SEND
        void send(TCB& sender, int receiverID, int data) {
            Message msg(sender.TID, receiverID, data);

            // خزن الرسالة
            queues[receiverID].push(msg);

            // WAKEUP
            if (waitingThreads.count(receiverID)) {
                TCB* receiver = waitingThreads[receiverID];
                waitingThreads.erase(receiverID);

                if (receiver->blockType == BlockType::MESSAGE) {
                    receiver->blockType = BlockType::NONE;
                    StateManager::transition(*receiver, State::READY);
                }
            }
        }

        // RECEIVE (Blocking)
        bool receive(TCB& receiver, Message& outMsg) {
            int id = receiver.TID;
            auto& q = queues[id];

            // ماكو رسائل → block
            if (q.empty()) {
                waitingThreads[id] = &receiver;
                receiver.blockType = BlockType::MESSAGE;
                StateManager::transition(receiver, State::WAITING);
                return false;
            }

            // استلام
            outMsg = q.front();
            q.pop();
            return true;
        }
};

#endif