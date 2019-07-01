#include "TestMessageReceiver.h"

TestMessageReceiver::TestMessageReceiver() {
}

std::list<const char*> TestMessageReceiver::getMessages() {
    return _messages;
}