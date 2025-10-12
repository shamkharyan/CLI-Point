#pragma once

#include "model/AppContext.h"
#include "Command.h"

class ExitCommand : public Command
{
public:
	ExitCommand(AppContext& context, IViewer& viewer, bool force);
	void execute() override;
private:
	bool m_force;
};