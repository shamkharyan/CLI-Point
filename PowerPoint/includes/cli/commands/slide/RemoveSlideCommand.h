#pragma once

#include "cli/commands/ICommand.h"
#include "core/ActionManager.h"
#include "model/Presentation.h"

namespace ppt::cli::cmds
{
	class RemoveSlideCommand : public ICommand
	{
	public:
		RemoveSlideCommand(core::ActionManager& actionManager, model::Presentation& presentation, std::size_t at);
		void execute() override;

	private:
		core::ActionManager& m_actionManager;
		model::Presentation& m_presentation;

		std::size_t m_at;
	};
}
