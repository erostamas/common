#pragma once

#include <vector>
#include <memory>

#include "ICommand.h"
#include "IMessageReceiver.h"

class ICommandAdapter {
public:
    std::vector<CommandPtr> getCommands() const {
        std::vector<CommandPtr> ret;
        for (const auto& receiver : _messageReceivers) {
            for (const auto& message : receiver->getMessages()) {
                ret.push_back(std::move(convertMessage(message.getMessageContent().c_str())));
            }
        }
        return ret;
    }

    virtual CommandPtr convertMessage(const char* message) const = 0;

    void registerMessageReceiver(MessageReceiverPtr&& messageReceiver) { _messageReceivers.push_back(std::move(messageReceiver)); }
private:
    std::vector<MessageReceiverPtr> _messageReceivers;
};

using CommandAdapterPtr = std::unique_ptr<ICommandAdapter>;