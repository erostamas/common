#pragma once

#include <string>
#include <thread>
#include <mutex>
#include <memory>
#include <boost/asio.hpp>

#include "UdpReceiver.h"

class UdpInterface {
public:
    UdpInterface(unsigned listenPort);

    void sendTo(const std::string& ipAddress
              , unsigned targetPort
              , const char* message
              , std::size_t length);
    void sendTo(const std::string& ipAddress
              , unsigned targetPort
              , std::string message);
    void sendTo(boost::asio::ip::udp::endpoint remoteEndpoint
              , std::string message);
    std::list<Message> getMessages();

private:
    std::shared_ptr<boost::asio::io_service> _ioService;
    std::shared_ptr<boost::asio::ip::udp::socket> _socket;
    unsigned _listenPort = 0;
    UdpReceiver _receiver;
};

using UdpInterfacePtr = std::unique_ptr<UdpInterface>;
