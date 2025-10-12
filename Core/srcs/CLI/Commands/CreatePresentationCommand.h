#pragma once

#include "model/AppContext.h"
#include "Command.h"

#include <string>

class CreatePresentationCommand : public Command
{
public:
	CreatePresentationCommand(AppContext& context, IViewer& viewer, const std::string& name);
	void execute() override;
private:
	std::string m_name;
};