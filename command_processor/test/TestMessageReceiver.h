#pragma once

#include <memory>
#include <list>

#include "IMessageReceiver.h"

class TestMessageReceiver : public IMessageReceiver {
public:
    TestMessageReceiver();

    virtual std::list<Message> getMessages() override;

    std::list<Message> _messages;
};