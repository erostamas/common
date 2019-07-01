#include "TestStringCommandAdapter.h"

#include <boost/algorithm/string.hpp>
#include <vector>

#include "TestCommands.h"

CommandPtr TestStringCommandAdapter::convertMessage(const char* message) const {
    std::vector<std::string> tokens;
    boost::split(tokens,message,boost::is_any_of(" "));
    if (tokens.size() != 2 || tokens[0] != "print") {
        return nullptr;
    } else {
        return std::unique_ptr<PrintCommand>(new PrintCommand(tokens[1]));
    }
    return nullptr;
}