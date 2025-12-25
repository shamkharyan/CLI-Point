#pragma once

#include "cli/commands/ICommand.h"
#include "model/Presentation.h"
#include "serialization/serializers/SerializerRegistry.h"
#include "core/ActionManager.h"

#include <memory>

namespace ppt::cli::cmds
{
	class SaveCommand : public ICommand
	{
	public:
		SaveCommand(
			const model::Presentation& presentation,
			const ser::SerializerRegistry& registry,
			core::ActionManager& actionManager,
			const std::string& filePath);

		void execute() override;
	private:
		const model::Presentation& m_presentation;
		const ser::SerializerRegistry& m_registry;
		core::ActionManager& m_actionManager;
		std::string m_filePath;
	};
}