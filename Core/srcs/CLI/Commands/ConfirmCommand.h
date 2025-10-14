#pragma once

#include "Command.h"

class ConfirmCommand : public Command
{
public:
	ConfirmCommand(AppContext& context) : Command(context) {}
	virtual ~ConfirmCommand() = default;

	virtual Result confirm(bool ans) = 0;
	virtual std::string confirmQuestion() const = 0;
};
