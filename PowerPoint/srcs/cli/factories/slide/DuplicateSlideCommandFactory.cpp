#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"
#include "cli/errors/MissingArgumentException.h"
#include "cli/factories/slide/DuplicateSlideCommandFactory.h"
#include "cli/utils/ArgParser.h"
#include "cli/commands/slide/DuplicateSlideCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> DuplicateSlideCommandFactory::createCommand(const Arguments& args)
{
	std::optional<std::size_t> at;
	std::optional<std::size_t> to;
	bool go = false;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-a" || argName == "--at")
			at = utils::ArgParser::parseNumber(argName, argVals);
		else if (argName == "-t" || argName == "--to")
			to = utils::ArgParser::parseNumber(argName, argVals);
		else if (argName == "-g" || argName == "--goto")
			go = utils::ArgParser::parseFlag(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	return std::make_unique<cmds::DuplicateSlideCommand>(at, to, go);
}