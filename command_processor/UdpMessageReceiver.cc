#include "UdpMessageReceiver.h"

UdpMessageReceiver::UdpMessageReceiver(unsigned listenPort) {
    _udpInterface = std::unique_ptr<UdpInterface>(new UdpInterface(listenPort));
    _udpInterface->startReceiveThread();
}

std::list<const char*> UdpMessageReceiver::getMessages() {
    return _udpInterface->getMessages();
}