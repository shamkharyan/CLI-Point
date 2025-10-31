#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"
#include "cli/factories/EditPresentationCommandFactory.h"
#include "cli/commands/EditPresentationCommand.h"
#include "cli/utils/ArgParser.h"

#include <optional>

using namespace ppt::cli;
using namespace ppt::cli::factories;



std::unique_ptr<cmds::ICommand> EditPresentationCommandFactory::createCommand(const Arguments& args)
{
	std::optional<std::string> name;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-n" || argName == "--name")
			name = utils::ArgParser::parseString(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	return std::make_unique<cmds::EditPresentationCommand>(name);
}

