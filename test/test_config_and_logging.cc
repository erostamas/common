#include <iostream>
#include "Config.h"

int main() {
    Config config("config.json");
    auto _redisIpAddress = config.get<std::string>("redis_ip_address", "192.168.1.247");
    LOG_INFO << "REDIS IP: " << _redisIpAddress;
    return 0;
}