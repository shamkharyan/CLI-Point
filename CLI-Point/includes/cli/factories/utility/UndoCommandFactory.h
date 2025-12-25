#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"
#include "core/ActionManager.h"

namespace ppt::cli::factories
{
	class UndoCommandFactory : public ICommandFactory
	{
	public:
		UndoCommandFactory(core::ActionManager& actionManager);
		std::unique_ptr<cmds::ICommand> createCommand(const ParsedRawCommand& args) override;
	private:
		core::ActionManager& m_actionManager;
	};
}
