#pragma once

#include "model/PPModel.h"
#include "core/ActionManager.h"
#include "cli/commands/ICommand.h"

namespace ppt::cli::cmds
{
	class UndoCommand : public ICommand
	{
	public:
		UndoCommand() = default;
		void execute() override
		{
			ppt::model::PPModel::instance().getContext().getActionManager().undo();
		}
	};
}