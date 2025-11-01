#include "cli/factories/utility/UndoCommandFactory.h"
#include "cli/commands/utility/UndoCommand.h"
#include "viewer/cli/CLIViewer.h"
#include "cli/commands/ICommand.h"
#include "cli/errors/InvalidArgumentException.h"

#include <memory>

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> UndoCommandFactory::createCommand(const Arguments& args)
{
	if (!args.empty())
		throw err::InvalidArgumentException(args.begin()->first);
	return std::make_unique<cmds::UndoCommand>();
}