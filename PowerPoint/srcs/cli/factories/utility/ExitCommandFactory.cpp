#include "cli/factories/utility/ExitCommandFactory.h"
#include "cli/commands/utility/ExitCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

ExitCommandFactory::ExitCommandFactory(core::IController& controller, viewer::IViewer& viewer) :
	m_controller(controller),
	m_viewer(viewer)
{
}

std::unique_ptr<cmds::ICommand> ExitCommandFactory::createCommand(const ValidatedRawCommand& rcmd)
{
	bool force = std::get<bool>(rcmd.arguments.at("force"));

	return std::make_unique<cmds::ExitCommand>(m_controller, m_viewer, force);
}