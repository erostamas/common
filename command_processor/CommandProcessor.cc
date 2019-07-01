#include "CommandProcessor.h"

void CommandProcessor::processCommands() {
    for (const auto& commandAdapter : _commandAdapters) {
        for (const auto& command : commandAdapter->getCommands()) {
            command->execute();
        }
    }
}

void CommandProcessor::registerCommandAdapter(CommandAdapterPtr&& commandAdapter) {
    _commandAdapters.push_back(std::move(commandAdapter));
}