#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/factories/ExitCommandFactory.h"
#include "cli/commands/ExitCommand.h"
#include "cli/utils/ArgParser.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

ExitCommandFactory::ExitCommandFactory(core::IController& controller, viewer::IViewer& viewer) :
	m_controller(controller),
	m_viewer(viewer)
{
}

std::unique_ptr<cmds::ICommand> ExitCommandFactory::createCommand(const Arguments& args)
{
	bool force = false;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-f" || argName == "--force")
			force = utils::ArgParser::parseFlag(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	return std::make_unique<cmds::ExitCommand>(m_controller, m_viewer, force);
}