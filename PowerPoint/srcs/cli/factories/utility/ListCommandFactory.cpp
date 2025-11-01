#include "cli/factories/utility/ListCommandFactory.h"
#include "cli/commands/utility/ListCommand.h"
#include "viewer/cli/CLIViewer.h"
#include "cli/commands/ICommand.h"
#include "cli/errors/InvalidArgumentException.h"

#include <memory>

using namespace ppt::cli;
using namespace ppt::cli::factories;

ListCommandFactory::ListCommandFactory(viewer::cli::CLIViewer& viewer) : m_viewer(viewer) {}

std::unique_ptr<cmds::ICommand> ListCommandFactory::createCommand(const Arguments& args)
{
	if (!args.empty())
		throw err::InvalidArgumentException(args.begin()->first);
	return std::make_unique<cmds::ListCommand>(m_viewer);
}