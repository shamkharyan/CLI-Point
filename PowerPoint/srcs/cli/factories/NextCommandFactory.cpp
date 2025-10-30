#include "cli/factories/NextCommandFactory.h"
#include "cli/commands/NextCommand.h"
#include "cli/commands/ICommand.h"
#include "cli/errors/InvalidArgumentException.h"

#include <memory>

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> NextCommandFactory::createCommand(const Arguments& args)
{
	if (!args.empty())
		throw err::InvalidArgumentException(args.begin()->first);
	return std::make_unique<cmds::NextCommand>();
}