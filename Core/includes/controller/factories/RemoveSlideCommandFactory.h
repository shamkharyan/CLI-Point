#pragma once

#include "controller/factories/ACommandFactory.h"

#include <string>

class RemoveSlideCommandFactory : public ACommandFactory
{
public:
    RemoveSlideCommandFactory(AppContext& context) :
        ACommandFactory(context) 
    {}

    std::unique_ptr<ACommand> createCommand(const Arguments& args) override;
};
