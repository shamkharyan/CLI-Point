#pragma once

#include "model/PPModel.h"
#include "core/ActionManager.h"
#include "cli/commands/ICommand.h"

namespace ppt::cli::cmds
{
	class RedoCommand : public ICommand
	{
	public:
		RedoCommand() = default;
		void execute() override
		{
			ppt::model::PPModel::instance().getContext().getActionManager().redo();
		}
	};
}