#pragma once

class PrintCommand : public ICommand {
public:
    PrintCommand(const std::string& printMessage)
    : _printMessage(printMessage) {}

    virtual void execute() override { std::cout << "Command executed: " << _printMessage << std::endl; }

private:
    std::string _printMessage;
};