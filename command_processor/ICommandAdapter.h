#pragma once

#include <vector>
#include <memory>

#include "ICommand.h"
#include "IMessageReceiver.h"

class ICommandAdapter {
public:
    virtual std::vector<CommandPtr> getCommands() = 0;
    
    void registerMessageReceiver(MessageReceiverPtr&& messageReceiver) { _messageReceivers.push_back(std::move(messageReceiver)); }
private:
    std::vector<MessageReceiverPtr> _messageReceivers;
};

using CommandAdapterPtr = std::unique_ptr<ICommandAdapter>;