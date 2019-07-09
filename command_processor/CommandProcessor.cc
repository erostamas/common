#include "CommandProcessor.h"
#include "Logging.h"

void CommandProcessor::processCommands() {
    for (const auto& commandAdapter : _commandAdapters) {
        for (const auto& command : commandAdapter->getCommands()) {
            LOG_DEBUG << "[CommandProcessor] Executing command" << std::endl;
            command->execute();
        }
    }
}

void CommandProcessor::registerCommandAdapter(CommandAdapterPtr&& commandAdapter) {
    _commandAdapters.push_back(std::move(commandAdapter));
}