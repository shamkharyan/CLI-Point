#pragma once

#include "cli/commands/ICommand.h"
#include "core/ActionManager.h"

namespace ppt::cli::cmds
{
	class UndoCommand : public ICommand
	{
	public:
		UndoCommand(core::ActionManager& actionManager);
		void execute() override;
	private:
		core::ActionManager& m_actionManager;
	};
}