#pragma once

#include <list>

class IMessageReceiver {
public:
    virtual std::list<const char*> getMessages() = 0;
};

using MessageReceiverPtr = std::unique_ptr<IMessageReceiver>;