#pragma once

#include "cli/commands/ICommand.h"

#include "model/Presentation.h"
#include "model/ShapeData.h"
#include "core/ActionManager.h"
#include "model/utils/GeometryData.h"
#include "model/utils/StyleData.h"

namespace ppt::cli::cmds
{
	class RemoveShapeCommand : public ICommand
	{
	public:
		RemoveShapeCommand(
			model::Presentation& model,
			core::ActionManager& actionManager,
			std::size_t at,
			std::size_t id
		);

		void execute() override;

	private:
		model::Presentation& m_model;
		core::ActionManager& m_actionManager;

		std::size_t m_at;
		std::size_t m_id;
	};
}
