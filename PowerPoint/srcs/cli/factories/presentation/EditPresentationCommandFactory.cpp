#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"
#include "cli/factories/presentation/RenamePresentationCommandFactory.h"
#include "cli/commands/presentation/RenamePresentationCommand.h"
#include "cli/utils/ArgParser.h"

#include <optional>

using namespace ppt::cli;
using namespace ppt::cli::factories;



std::unique_ptr<cmds::ICommand> RenamePresentationCommandFactory::createCommand(const Arguments& args)
{
	std::optional<std::string> name;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-n" || argName == "--name")
			name = utils::ArgParser::parseString(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	return std::make_unique<cmds::RenamePresentationCommand>(name);
}

