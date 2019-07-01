#include "ICommandAdapter.h"

class TestStringCommandAdapter : public ICommandAdapter {
public:
    virtual CommandPtr convertMessage(const char* message) const override;
};