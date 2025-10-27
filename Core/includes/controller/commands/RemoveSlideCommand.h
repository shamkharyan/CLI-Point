#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "controller/commands/ACommand.h"

#include <string>

class RemoveSlideCommand : public ACommand
{
public:
	RemoveSlideCommand(AppContext& context, std::size_t at);
	void execute() override;

private:
	std::size_t m_at;
};
