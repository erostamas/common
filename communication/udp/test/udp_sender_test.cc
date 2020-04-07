#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

#include "UdpSender.h"
#include "Logging.h"

int main() {
    std::string x = "DEBUG";
    init_logging(std::cout, x);
    UdpSender udpSender("192.168.1.181", 50005);
    while(true) {
        std::string msg = std::to_string(std::time(0));
        udpSender.send(msg);
        std::cout << "Sent message: " << msg << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}