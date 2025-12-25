#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"
#include "core/ActionManager.h"
#include "model/Presentation.h"

namespace ppt::cli::factories
{
	class MoveLayerCommandFactory : public ICommandFactory
	{
	public:
		MoveLayerCommandFactory(core::ActionManager& actionManager, model::Presentation& presentation);
		std::unique_ptr<cmds::ICommand> createCommand(const ParsedRawCommand& args) override;
	private:
		core::ActionManager& m_actionManager;
		model::Presentation& m_presentation;
	};
}
