#pragma once

#include "ICommand.h"
#include "ICommandAdapter.h"

class CommandProcessor {
public:
    CommandProcessor() = default;

    void processCommands();
    void registerCommandAdapter(CommandAdapterPtr&& commandAdapter);

private:
    std::vector<CommandAdapterPtr> _commandAdapters;
};