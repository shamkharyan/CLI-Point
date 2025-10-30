#include "cli/factories/PrevCommandFactory.h"
#include "cli/commands/PrevCommand.h"
#include "cli/commands/ICommand.h"
#include "cli/errors/InvalidArgumentException.h"

#include <memory>

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> PrevCommandFactory::createCommand(const Arguments& args)
{
	if (!args.empty())
		throw err::InvalidArgumentException(args.begin()->first);
	return std::make_unique<cmds::PrevCommand>();
}