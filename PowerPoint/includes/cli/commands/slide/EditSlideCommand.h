#pragma once

#include "cli/commands/ICommand.h"
#include "model/utils/Color.h"
#include "model/Presentation.h"
#include "core/ActionManager.h"


namespace ppt::cli::cmds
{
	class EditSlideCommand : public ICommand
	{
	public:
		EditSlideCommand(
			core::ActionManager& actionManager,
			model::Presentation& presentation, 
			std::size_t at, 
			model::utils::Color color
		);

		void execute() override;

	private:
		core::ActionManager& m_actionManager;
		model::Presentation& m_presentation;

		std::size_t m_at;
		model::utils::Color m_color;
	};
}
