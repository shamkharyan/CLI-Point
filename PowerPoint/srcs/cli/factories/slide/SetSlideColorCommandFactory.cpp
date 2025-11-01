#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"
#include "cli/errors/MissingArgumentException.h"
#include "cli/factories/slide/SetSlideColorCommandFactory.h"
#include "cli/utils/ArgParser.h"
#include "cli/commands/slide/SetSlideColorCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> SetSlideColorCommandFactory::createCommand(const Arguments& args)
{
	std::optional<model::utils::Color> color;
	std::optional<std::size_t> at;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-a" || argName == "--at")
			at = utils::ArgParser::parseNumber(argName, argVals);
		else if (argName == "-c" || argName == "--color")
			color = utils::ArgParser::parseColor(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}
	if (!color)
		throw err::MissingArgumentException("-c or --color");

	return std::make_unique<cmds::SetSlideColorCommand>(at, color.value());
}