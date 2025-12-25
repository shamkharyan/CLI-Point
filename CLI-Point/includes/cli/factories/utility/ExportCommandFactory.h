#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"
#include "model/Presentation.h"
#include "serialization/exporters/ExporterRegistry.h"

namespace ppt::cli::factories
{
	class ExportCommandFactory : public ICommandFactory
	{
	public:
		ExportCommandFactory(const model::Presentation& presentation, const ser::ExporterRegistry& registry);
		std::unique_ptr<cmds::ICommand> createCommand(const ParsedRawCommand& args) override;
	private:
		const model::Presentation& m_presentation;
		const ser::ExporterRegistry& m_registry;
	};
}
