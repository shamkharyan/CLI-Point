#pragma once

#include "cli/commands/ICommand.h"
#include "model/Presentation.h"
#include "serialization/serializers/SerializerRegistry.h"

#include <memory>

namespace ppt::cli::cmds
{
	class SaveCommand : public ICommand
	{
	public:
		SaveCommand(
			const model::Presentation& presentation, 
			const ser::SerializerRegistry& registry,
			const std::string& filePath);

		void execute() override;
	private:
		const model::Presentation& m_presentation;
		const ser::SerializerRegistry& m_registry;
		std::string m_filePath;
	};
}