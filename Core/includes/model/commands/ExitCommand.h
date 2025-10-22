#pragma once

#include "model/AppContext.h"
#include "model/commands/AConfirmCommand.h"
#include "viewer/IViewer.h"

class ExitCommand : public AConfirmCommand
{
public:
	ExitCommand(AppContext& context, IViewer& viewer, bool force);
	void execute() override;
private:
	bool m_force;
};