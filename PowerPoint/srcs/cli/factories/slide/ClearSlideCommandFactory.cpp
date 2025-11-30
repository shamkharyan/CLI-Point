#include "cli/errors/InvalidArgumentException.h"
#include "cli/factories/slide/ClearSlideCommandFactory.h"
#include "cli/utils/ArgParser.h"
#include "cli/commands/slide/ClearSlideCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> ClearSlideCommandFactory::createCommand(const Arguments& args)
{
	std::optional<std::size_t> at;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-a" || argName == "--at")
			at = utils::ArgParser::parseNumber(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	return std::make_unique<cmds::ClearSlideCommand>(m_actionManager, m_presentation, at);
}