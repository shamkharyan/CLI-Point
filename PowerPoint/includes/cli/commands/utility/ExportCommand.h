#pragma once

#include "cli/commands/ICommand.h"
#include "model/Presentation.h"
#include "serialization/exporters/ExporterRegistry.h"

#include <memory>

namespace ppt::cli::cmds
{
	class ExportCommand : public ICommand
	{
	public:
		ExportCommand(
			const model::Presentation& presentation,
			const ser::ExporterRegistry& registry,
			const std::string& filePath,
			std::size_t at);

		void execute() override;
	private:
		const model::Presentation& m_presentation;
		const ser::ExporterRegistry& m_registry;
		std::string m_filePath;
		std::size_t m_at;
	};
}