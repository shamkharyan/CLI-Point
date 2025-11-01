#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"
#include "cli/factories/presentation/CreatePresentationCommandFactory.h"
#include "cli/commands/presentation/CreatePresentationCommand.h"
#include "cli/utils/ArgParser.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

CreatePresentationCommandFactory::CreatePresentationCommandFactory(viewer::IViewer& viewer) : m_viewer(viewer) {}

std::unique_ptr<cmds::ICommand> CreatePresentationCommandFactory::createCommand(const Arguments& args)
{
	std::optional<std::string> name;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-n" || argName == "--name")
			name = utils::ArgParser::parseString(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	return std::make_unique<cmds::CreatePresentationCommand>(m_viewer, name);
}

