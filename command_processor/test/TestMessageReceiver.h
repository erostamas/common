#pragma once

#include <memory>
#include <list>

#include "IMessageReceiver.h"

class TestMessageReceiver : public IMessageReceiver {
public:
    TestMessageReceiver();

    virtual std::list<const char*> getMessages() override;

    std::list<const char*> _messages;
};