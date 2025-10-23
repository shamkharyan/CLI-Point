#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "controller/commands/AConfirmCommand.h"

class ExitCommand : public AConfirmCommand
{
public:
	ExitCommand(AppContext& context, IViewer& viewer, bool force);
	void execute() override;
private:
	bool m_force;
};