#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"
#include "cli/errors/MissingArgumentException.h"
#include "cli/factories/GotoSlideCommandFactory.h"
#include "cli/utils/ArgParser.h"
#include "cli/commands/GotoSlideCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> GotoSlideCommandFactory::createCommand(const Arguments& args)
{
	std::optional<std::size_t> at;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-a" || argName == "--at")
			at = utils::ArgParser::parseNumber(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	if (!at)
		throw err::MissingArgumentException("-a or --at");

	return std::make_unique<cmds::GotoSlideCommand>(at.value());
}