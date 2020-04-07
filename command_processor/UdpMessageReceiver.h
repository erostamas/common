#pragma once

#include <memory>
#include <list>

#include "IMessageReceiver.h"
#include "UdpInterface.h"

class UdpMessageReceiver : public IMessageReceiver {
public:
    UdpMessageReceiver(unsigned listenPort);

    virtual std::list<Message> getMessages() override;

private:
    std::unique_ptr<UdpReceiver> _udpReceiver = nullptr;
};