#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"
#include "cli/factories/EditSlideCommandFactory.h"
#include "cli/utils/ArgParser.h"
#include "cli/commands/EditSlideCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> EditSlideCommandFactory::createCommand(const Arguments& args)
{
	std::optional<model::utils::Color> bgColor;
	std::optional<std::size_t> at;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-a" || argName == "--at")
			at = utils::ArgParser::parseNumber(argName, argVals);
		else if (argName == "-b" || argName == "--bg")
			bgColor = utils::ArgParser::parseColor(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	return std::make_unique<cmds::EditSlideCommand>(at, bgColor);
}