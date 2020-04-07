#include <iostream>

#include "UdpReceiver.h"
#include "Logging.h"

int main() {
    std::string x = "DEBUG";
    init_logging(std::cout, x);
    UdpReceiver udpReceiver(50001);
    while(true) {
    }
    return 0;
}