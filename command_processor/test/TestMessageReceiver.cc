#include "TestMessageReceiver.h"

TestMessageReceiver::TestMessageReceiver() {
}

std::list<Message> TestMessageReceiver::getMessages() {
    return _messages;
}