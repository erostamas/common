#include <iostream>

#include "UdpInterface.h"
#include "UdpSender.h"
#include "UdpReceiver.h"
#include "Logging.h"

UdpInterface::UdpInterface(unsigned listenPort)
: _ioService(std::make_shared<boost::asio::io_service>())
, _socket(std::make_shared<boost::asio::ip::udp::socket>(*_ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("0.0.0.0"), listenPort)))
, _listenPort(listenPort)
, _receiver(_listenPort, _socket, _ioService) {
}

void UdpInterface::sendTo(const std::string& ipAddress
                        , unsigned port
                        , const char* message
                        , std::size_t length) {
    UdpSender sender(ipAddress, port);
    sender.send(message, length);
}

void UdpInterface::sendTo(const std::string& ipAddress
                        , unsigned port
                        , std::string message) {
    sendTo(ipAddress, port, message.c_str(), message.size());
}

void UdpInterface::sendTo(boost::asio::ip::udp::endpoint remoteEndpoint
                        , std::string message) {
    UdpSender sender(remoteEndpoint);
    sender.send(message.c_str(), message.size());
}

std::list<Message> UdpInterface::getMessages() {
    return _receiver.getMessages();
}