#pragma once

#include <boost/asio.hpp>
#include <string>
#include <memory>

class UdpSender {
public:
    UdpSender(const std::string& ipAddress, unsigned port, std::shared_ptr<boost::asio::ip::udp::socket> socket = nullptr, std::shared_ptr<boost::asio::io_service> ioService = nullptr);
    UdpSender(boost::asio::ip::udp::endpoint remoteEndpoint, std::shared_ptr<boost::asio::ip::udp::socket> socket = nullptr, std::shared_ptr<boost::asio::io_service> ioService = nullptr);
    ~UdpSender();

    void send(const char* message, std::size_t length);
    void send(const std::string& message);

private:
    std::shared_ptr<boost::asio::io_service> _ioService;
    std::shared_ptr<boost::asio::ip::udp::socket> _socket;
    boost::asio::ip::udp::endpoint _remoteEndpoint;
};