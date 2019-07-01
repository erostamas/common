#include "TestStringCommandAdapter.h"
#include "TestCommands.h"

CommandPtr TestStringCommandAdapter::convertMessage(const char* message) const {
    return std::unique_ptr<PrintCommand>(new PrintCommand(message));
}