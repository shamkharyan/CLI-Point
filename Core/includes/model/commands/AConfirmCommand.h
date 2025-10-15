#pragma once

#include "ACommand.h"

class AConfirmCommand : public ACommand
{
public:
	AConfirmCommand(AppContext& context) : ACommand(context) {}
	virtual ~AConfirmCommand() = default;

	virtual Result confirm(bool ans) = 0;
	virtual std::string confirmQuestion() const = 0;
};
