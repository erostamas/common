#pragma once

#include <memory>

class ICommand {
public:
    virtual void execute() = 0;

};

using CommandPtr = std::unique_ptr<ICommand>;