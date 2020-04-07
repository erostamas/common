#pragma once

#include <list>

#include "Message.h"

class IMessageReceiver {
public:
    virtual std::list<Message> getMessages() = 0;
};

using MessageReceiverPtr = std::unique_ptr<IMessageReceiver>;