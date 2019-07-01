#pragma once

#include <memory>
#include <list>

#include "IMessageReceiver.h"
#include "udp/UdpInterface.h"

class UdpMessageReceiver : public IMessageReceiver {
public:
    UdpMessageReceiver(unsigned listenPort);

    virtual std::list<const char*> getMessages() override;

private:
    std::unique_ptr<UdpInterface> _udpInterface = nullptr;
};