#include "UdpMessageReceiver.h"

UdpMessageReceiver::UdpMessageReceiver(unsigned listenPort) {
    _udpReceiver = std::unique_ptr<UdpReceiver>(new UdpReceiver(listenPort));
    _udpReceiver->startReceiveThread();
}

std::list<const char*> UdpMessageReceiver::getMessages() {
    return _udpReceiver->getMessages();
}