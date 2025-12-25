#pragma once

#include "cli/commands/ICommand.h"
#include "core/ActionManager.h"

namespace ppt::cli::cmds
{
	class RedoCommand : public ICommand
	{
	public:
		RedoCommand(core::ActionManager& actionManager);
		void execute() override;
	private:
		core::ActionManager& m_actionManager;
	};
}