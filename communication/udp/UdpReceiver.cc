#include <boost/bind.hpp>
#include <iostream>
#include <thread>

#include "UdpReceiver.h"
#include "Logging.h"
#include "UdpSender.h"

UdpReceiver::UdpReceiver(unsigned listenPort, std::shared_ptr<boost::asio::ip::udp::socket> socket, std::shared_ptr<boost::asio::io_service> ioService)
: _ioService(ioService == nullptr ? std::make_shared<boost::asio::io_service>() : ioService)
, _socket(socket == nullptr ? std::make_shared<boost::asio::ip::udp::socket>(*_ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("0.0.0.0"), listenPort)) : socket)
, _listenPort(listenPort) {
    startReceiveThread();
}

UdpReceiver::~UdpReceiver() {
}

void UdpReceiver::startReceiveThread() {
    _receiveThread = std::thread(&UdpReceiver::receiveThread, this);
}

void UdpReceiver::startReceive() {
    _socket->async_receive_from(boost::asio::buffer(_recvBuffer)
                             , _remoteEndpoint
                             , boost::bind(&UdpReceiver::handleReceive
                                        , this
                                        , boost::asio::placeholders::error
                                        , boost::asio::placeholders::bytes_transferred)
                              );
}

void UdpReceiver::handleReceive(const boost::system::error_code& error
                              , std::size_t bytes_transferred) {
        if (!error || error == boost::asio::error::message_size) {
            std::string msg(std::string(_recvBuffer.data(), bytes_transferred));
            LOG_DEBUG << "[UdpReceiver] Received message: '" << msg << "' from: '" << _remoteEndpoint << "'";
            _messageContainerMutex.lock();
            _messages.emplace_back(msg, _remoteEndpoint.address(), _remoteEndpoint.port());
            _messageContainerMutex.unlock();
        }
        startReceive();
}

std::list<Message> UdpReceiver::getMessages() {
    _messageContainerMutex.lock();
    auto tmp = _messages;
    _messages.clear();
    _messageContainerMutex.unlock();
    return tmp;
}

void UdpReceiver::receiveThread() {
    try {
        LOG_INFO << "[UdpInterface] Listening on port: " << _listenPort;
        startReceive();
        _ioService->run();
    } catch (const std::exception& ex) {
        LOG_ERROR << "[UdpInterface] Exception on receive thread: " << ex.what() << std::endl;
    }
}
