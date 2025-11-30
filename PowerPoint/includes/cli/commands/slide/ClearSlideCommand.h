#pragma once

#include "cli/commands/ICommand.h"
#include "viewer/IViewer.h"
#include "model/Presentation.h"
#include "core/ActionManager.h"

#include <optional>
#include <string>

namespace ppt::cli::cmds
{
	class ClearSlideCommand : public ICommand
	{
	public:
		ClearSlideCommand(
			core::ActionManager& actionManager,
			model::Presentation& presentation,
			std::optional<std::size_t> at) : 	
			m_actionManager(actionManager),
			m_presentation(presentation),
			m_at(at)
		{
		}
		void execute() override;

	private:
		core::ActionManager& m_actionManager;
		model::Presentation& m_presentation;
		std::optional<std::size_t> m_at;
	};
}
