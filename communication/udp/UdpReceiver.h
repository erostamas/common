#pragma once

#include <boost/asio.hpp>
#include <list>
#include <mutex>
#include <thread>

#include "Message.h"

class UdpReceiver {
public:
    UdpReceiver(unsigned listenPort, std::shared_ptr<boost::asio::ip::udp::socket> socket = nullptr, std::shared_ptr<boost::asio::io_service> ioService = nullptr);
    ~UdpReceiver();

    std::list<Message> getMessages();
private:
    void receiveThread();
    void startReceiveThread();
    void startReceive();
    void handleReceive(const boost::system::error_code& error
                     , std::size_t bytes_transferred);

    std::shared_ptr<boost::asio::io_service> _ioService;
    std::shared_ptr<boost::asio::ip::udp::socket> _socket;
    boost::asio::ip::udp::endpoint _remoteEndpoint;
    std::array<char, 1024> _recvBuffer;
    std::list<Message> _messages;
    std::mutex _messageContainerMutex;
    std::thread _receiveThread;
    int _listenPort;
};
