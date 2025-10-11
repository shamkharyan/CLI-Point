#pragma once

#include "model/AppContext.h"
#include "Command.h"

class ExitCommand : public Command
{
public:
	ExitCommand(AppContext& context);
	void execute() override;
};