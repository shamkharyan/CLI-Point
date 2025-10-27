#pragma once

#include "controller/factories/ACommandFactory.h"

#include <string>

class AddSlideCommandFactory : public ACommandFactory
{
public:
    AddSlideCommandFactory(AppContext& context) :
        ACommandFactory(context) {}

    std::unique_ptr<ACommand> createCommand(const Arguments& args) override;
};
