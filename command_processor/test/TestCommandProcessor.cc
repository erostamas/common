#include <gmock/gmock.h>

#include "TestStringCommandAdapter.h"
#include "CommandProcessor.h"

TEST(TestConfig, test_x) {
    std::unique_ptr<TestStringCommandAdapter> adapter(new TestStringCommandAdapter());
    std::unique_ptr<TestMessageReceiver> receiver(new TestMessageReceiver());
    adapter->regiterMessageReceiver(std::move(receiver));
    CommandProcessor commandProcessor;
    commandProcessor.registerCommandAdapter(std::move(adapter));
    std::cout << "hello" << std::endl;
}


