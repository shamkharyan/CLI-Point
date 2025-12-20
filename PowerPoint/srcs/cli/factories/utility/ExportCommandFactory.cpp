#include "cli/factories/utility/ExportCommandFactory.h"
#include "cli/commands/utility/ExportCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

ExportCommandFactory::ExportCommandFactory(
	const model::Presentation& presentation,
	const ser::ExporterRegistry& registry) :
	m_presentation(presentation),
	m_registry(registry)
{
}

std::unique_ptr<cmds::ICommand> ExportCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	auto path = std::get<std::string>(rcmd.arguments.at("path"));
	auto at = std::get<std::size_t>(rcmd.arguments.at("at"));

	return std::make_unique<cmds::ExportCommand>(m_presentation, m_registry, path, at);
}