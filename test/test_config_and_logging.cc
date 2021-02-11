#include <iostream>
#include <thread>

#include "Config.h"
#include "Logging.h"

int main() {
    init_logging("logs", "log_%Y%m%d_%H%M%S", "INFO", 1024, 3 * 1024);
    Config config("config.json");
    auto _redisIpAddress = config.get<std::string>("redis_ip_address", "192.168.1.247");
    while(true) {
        LOG_INFO << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}