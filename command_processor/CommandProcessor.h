#pragma once

#include "ICommand.h"

class CommandProcessor {
public:
    CommandProcessor() = default;

    void processCommands();
    void registerCommandAdapter(CommandAdapterPtr&& commandAdapter);

private:
    std::vector<ICommandAdapter> _commandAdapters;
};