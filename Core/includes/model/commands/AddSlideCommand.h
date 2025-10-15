#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "model/commands/ACommand.h"

class AddSlideCommand : public ACommand
{
public:
	AddSlideCommand(AppContext& context, int at);
	Result execute() override;
private:
	int m_at;
};
