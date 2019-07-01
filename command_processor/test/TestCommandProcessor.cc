#include <gmock/gmock.h>

#include "TestStringCommandAdapter.h"
#include "TestMessageReceiver.h"
#include "CommandProcessor.h"

TEST(TestConfig, test_x) {
    std::unique_ptr<TestStringCommandAdapter> adapter(new TestStringCommandAdapter());
    std::unique_ptr<TestMessageReceiver> receiver(new TestMessageReceiver());
    receiver->_messages.push_back("print x");
    receiver->_messages.push_back("print y");
    receiver->_messages.push_back("something else");
    adapter->registerMessageReceiver(std::move(receiver));
    CommandProcessor commandProcessor;
    commandProcessor.registerCommandAdapter(std::move(adapter));
    commandProcessor.processCommands();
}


