#pragma once

#include "cli/commands/ICommand.h"

#include "model/Presentation.h"
#include "model/ShapeData.h"
#include "core/ActionManager.h"

#include "visualization/ShapeRegistry.h"

namespace ppt::cli::cmds
{
	class AddShapeCommand : public ICommand
	{
	public:
		AddShapeCommand(
			model::Presentation& model,
			core::ActionManager& actionManager,
			const vis::ShapeRegistry& registry,
			std::size_t at,
			model::ShapeData data,
			std::size_t zIndex
		);

		void execute() override;

	private:
		model::Presentation& m_model;
		core::ActionManager& m_actionManager;
		const vis::ShapeRegistry& m_registry;

		std::size_t m_at;
		model::ShapeData m_data;
		std::size_t m_zIndex;
	};
}
