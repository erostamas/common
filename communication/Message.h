#pragma once

#include <string>
#include <boost/asio.hpp>

class Message {
public:
    Message(const std::string& content, boost::asio::ip::address ipAddress, int port)
    : _messageContent(content)
    , _ipAddress(ipAddress)
    , _port(port) {}

    std::string getMessageContent() const { return _messageContent; }
    boost::asio::ip::address getIpAddress() const { return _ipAddress; }
    int getPort() const { return _port; }

private:
    std::string _messageContent;
    boost::asio::ip::address _ipAddress;
    int _port;
};