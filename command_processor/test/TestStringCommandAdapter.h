#include "ICommandAdapter.h"

class TestStringCommandAdapter : public ICommandAdapter {
public:
    virtual std::vector<CommandPtr> getCommands() override;
};