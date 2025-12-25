#include "cli/factories/utility/ExitCommandFactory.h"
#include "cli/commands/utility/ExitCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

ExitCommandFactory::ExitCommandFactory(
	CLIController& controller,
	CLIViewer& viewer,
	model::Presentation& presentation) :
	m_controller(controller),
	m_viewer(viewer),
	m_presentation(presentation)
{
}

std::unique_ptr<cmds::ICommand> ExitCommandFactory::createCommand(const ParsedRawCommand& rcmd)
{
	bool force = std::get<bool>(rcmd.arguments.at("force"));

	return std::make_unique<cmds::ExitCommand>(m_controller, m_viewer, m_presentation, force);
}