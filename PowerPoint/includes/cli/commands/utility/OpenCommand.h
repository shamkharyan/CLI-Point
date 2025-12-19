#pragma once

#include "cli/commands/ICommand.h"
#include "model/Presentation.h"
#include "serialization/SerializerRegistry.h"

#include <memory>

namespace ppt::cli::cmds
{
	class OpenCommand : public ICommand
	{
	public:
		OpenCommand(
			model::Presentation& presentation,
			const ser::SerializerRegistry& registry,
			const std::string& filePath);

		void execute() override;
	private:
		model::Presentation& m_presentation;
		const ser::SerializerRegistry& m_registry;
		std::string m_filePath;
	};
}