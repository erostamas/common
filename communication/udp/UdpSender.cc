#include "UdpSender.h"

#include <string>
#include <boost/bind.hpp>

#include "Logging.h"

UdpSender::UdpSender(const std::string& targetAddress, unsigned targetPort, std::shared_ptr<boost::asio::ip::udp::socket> socket, std::shared_ptr<boost::asio::io_service> ioService)
: UdpSender(boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(targetAddress), targetPort), socket) {
}

UdpSender::UdpSender(boost::asio::ip::udp::endpoint remoteEndpoint, std::shared_ptr<boost::asio::ip::udp::socket> socket, std::shared_ptr<boost::asio::io_service> ioService)
: _ioService(ioService == nullptr ? std::make_shared<boost::asio::io_service>() : ioService)
, _socket(socket == nullptr ? std::make_shared<boost::asio::ip::udp::socket>(*_ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("0.0.0.0"), 0)) : socket)
, _remoteEndpoint(remoteEndpoint) {
}

UdpSender::~UdpSender() {
    _socket->close();
}

void UdpSender::send(const char* message, std::size_t length) {
    boost::system::error_code err;
    _socket->send_to(boost::asio::buffer(message, length), _remoteEndpoint, 0, err);
}

void UdpSender::send(const std::string& message) {
    send(message.c_str(), message.size());
}
