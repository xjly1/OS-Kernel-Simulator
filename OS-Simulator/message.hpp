#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H

struct Message {
    int senderID;
    int receiverID;
    int data;

    Message(int s, int r, int d) : senderID(s), receiverID(r), data(d) {}
};

#endif