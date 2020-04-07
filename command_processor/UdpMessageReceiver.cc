#include "UdpMessageReceiver.h"

UdpMessageReceiver::UdpMessageReceiver(unsigned listenPort) {
    _udpReceiver = std::unique_ptr<UdpReceiver>(new UdpReceiver(listenPort));
}

std::list<Message> UdpMessageReceiver::getMessages() {
    return _udpReceiver->getMessages();
}