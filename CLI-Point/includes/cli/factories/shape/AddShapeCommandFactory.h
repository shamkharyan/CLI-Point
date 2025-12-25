#pragma once

#include "cli/factories/ICommandFactory.h"
#include "core/ActionManager.h"
#include "model/Presentation.h"
#include "visualization/meta/ShapeRegistry.h"

namespace ppt::cli::factories
{
	class AddShapeCommandFactory : public ICommandFactory
	{
	public:
		AddShapeCommandFactory(
			core::ActionManager& actionManager, 
			model::Presentation& presentation,
			const vis::ShapeRegistry& registry
		);

		std::unique_ptr<cmds::ICommand> createCommand(const ParsedRawCommand& args) override;
	private:
		void prepareAdjustments(const std::string& type, std::vector<float>& adjustments);
	private:
		core::ActionManager& m_actionManager;
		model::Presentation& m_presentation;
		const vis::ShapeRegistry& m_registry;
	};
}
