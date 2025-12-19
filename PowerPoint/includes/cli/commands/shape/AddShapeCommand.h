#pragma once

#include "cli/commands/ICommand.h"

#include "model/Presentation.h"
#include "model/ShapeData.h"
#include "core/ActionManager.h"
#include "model/utils/GeometryData.h"
#include "model/utils/StyleData.h"
#include "model/utils/TextData.h"

#include <optional>


namespace ppt::cli::cmds
{
	class AddShapeCommand : public ICommand
	{
	public:
		AddShapeCommand(
			model::Presentation& model,
			core::ActionManager& actionManager,
			std::size_t at,
			model::utils::ShapeType type,
			const model::utils::GeometryData& geometry,
			const model::utils::StyleData& style,
			std::size_t zIndex
		);

		void execute() override;

	private:
		model::Presentation& m_model;
		core::ActionManager& m_actionManager;

		std::size_t m_at;
		model::utils::ShapeType m_type;
		model::utils::GeometryData m_geometry;
		model::utils::StyleData m_style;
		std::size_t m_zIndex;
	};
}
