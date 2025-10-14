#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "Command.h"

class AddSlideCommand : public Command
{
public:
	AddSlideCommand(AppContext& context, int at);
	Result execute() override;
private:
	int m_at;
};
