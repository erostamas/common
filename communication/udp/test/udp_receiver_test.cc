#include <iostream>

#include "UdpInterface.h"
#include "Logging.h"

int main() {
    std::string x = "DEBUG";
    init_logging(std::cout, x);
    UdpInterface udpInterface(50001);
    udpInterface.startReceiveThread();
    while(true) {
    }
    return 0;
}