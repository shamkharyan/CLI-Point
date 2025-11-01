#include "cli/errors/InvalidArgumentException.h"
#include "cli/factories/slide/AddSlideCommandFactory.h"
#include "cli/utils/ArgParser.h"
#include "cli/commands/slide/AddSlideCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> AddSlideCommandFactory::createCommand(const Arguments& args)
{
	std::optional<model::utils::Color> color;
	std::optional<std::size_t> at;
	bool go = false;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-a" || argName == "--at")
			at = utils::ArgParser::parseNumber(argName, argVals);
		else if (argName == "-c" || argName == "--color")
			color = utils::ArgParser::parseColor(argName, argVals);
		else if (argName == "-g" || argName == "--goto")
			go = utils::ArgParser::parseFlag(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	return std::make_unique<cmds::AddSlideCommand>(at, color, go);
}