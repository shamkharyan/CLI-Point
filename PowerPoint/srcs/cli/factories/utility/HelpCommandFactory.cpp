#include "cli/factories/utility/HelpCommandFactory.h"
#include "cli/commands/utility/HelpCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

HelpCommandFactory::HelpCommandFactory(CommandRegistry& registry, CLIViewer& viewer) :
	m_registry(registry),
	m_viewer(viewer)
{
}

std::unique_ptr<cmds::ICommand> HelpCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	auto specificCommandName = std::get<std::string>(rcmd.arguments.at("command"));

	return std::make_unique<cmds::HelpCommand>(m_registry, m_viewer, specificCommandName);
}