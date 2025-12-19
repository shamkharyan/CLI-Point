#pragma once

#include "cli/commands/ICommand.h"
#include "model/utils/Color.h"
#include "model/Presentation.h"
#include "core/ActionManager.h"

#include <optional>
#include <string>

namespace ppt::cli::cmds
{
	class MoveLayerCommand : public ICommand
	{
	public:
		MoveLayerCommand(
			core::ActionManager& actionManager,
			model::Presentation& presentation,
			std::size_t at,
			std::size_t zFrom,
			std::size_t zTo);

		void execute() override;
	private:
		core::ActionManager& m_actionManager;
		model::Presentation& m_presentation;

		std::size_t m_at;
		std::size_t m_zFrom;
		std::size_t m_zTo;
	};
}
