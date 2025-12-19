#pragma once

#include "cli/commands/ICommand.h"
#include "model/utils/Color.h"
#include "model/Presentation.h"
#include "core/ActionManager.h"

#include <optional>
#include <string>

namespace ppt::cli::cmds
{
	class RemoveLayerCommand : public ICommand
	{
	public:
		RemoveLayerCommand(
			core::ActionManager& actionManager,
			model::Presentation& presentation,
			std::size_t at,
			std::size_t zIndex);

		void execute() override;
	private:
		core::ActionManager& m_actionManager;
		model::Presentation& m_presentation;

		std::size_t m_at;
		std::size_t m_zIndex;
	};
}
