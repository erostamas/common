#pragma once

#include <memory>

class ICommand {
public:
    ICommand(uint64_t id)
    : _id(id) {}

    virtual void execute() = 0;

    uint64_t getId() { return _id; }

private:
    uint64_t _id = 0;
};

using CommandPtr = std::unique_ptr<ICommand>;