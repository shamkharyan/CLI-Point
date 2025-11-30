#pragma once

#include "cli/commands/ICommand.h"
#include "model/utils/Color.h"
#include "model/Presentation.h"
#include "core/ActionManager.h"

#include <optional>
#include <string>

namespace ppt::cli::cmds
{
	class AddSlideCommand : public ICommand
	{
	public:
		AddSlideCommand(
			core::ActionManager& actionManager,
			model::Presentation& presentation, 
			std::optional<std::size_t> at, 
			std::optional<model::utils::Color> color, 
			bool go) :
			m_actionManager(actionManager),
			m_presentation(presentation),
			m_at(at),
			m_color(color),
			m_goto(go)
		{ }

		void execute() override;
	private:
		core::ActionManager& m_actionManager;
		model::Presentation& m_presentation;
		std::optional<std::size_t> m_at;
		std::optional<model::utils::Color> m_color;
		bool m_goto;
	};
}
