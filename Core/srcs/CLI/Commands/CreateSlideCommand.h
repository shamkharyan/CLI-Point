#pragma once

#include "model/AppContext.h"
#include "Command.h"

#include <string>

class CreateSlideCommand : public Command
{
public:
	CreateSlideCommand(AppContext& context);
	void execute() override;
private:
	std::string m_name;
};