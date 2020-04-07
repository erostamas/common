#include <iostream>

#include "UdpInterface.h"
#include "Logging.h"

int main() {
    std::string x = "DEBUG";
    init_logging(std::cout, x);
    UdpInterface udpInterface(50001);
    while(true) {
        for(const auto& m : udpInterface.getMessages()) {
            udpInterface.sendTo(boost::asio::ip::udp::endpoint(m.getIpAddress(), m.getPort()), "thanks for your message: '" + m.getMessageContent() + "'");
        }
    }
    return 0;
}