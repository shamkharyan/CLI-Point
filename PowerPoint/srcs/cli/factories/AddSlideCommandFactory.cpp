#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"
#include "cli/factories/AddSlideCommandFactory.h"
#include "cli/utils/Converter.h"
#include "cli/commands/AddSlideCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> AddSlideCommandFactory::createCommand(const Arguments& args)
{
	std::optional<model::utils::Color> bgColor;
	std::optional<std::size_t> at;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-at")
		{
			if (argVals.size() != 1)
				throw err::InvalidArgumentValueException("'-at' takes exactly one value");
			if (auto ans = utils::Converter::stringToSizeT(argVals[0]))
				at = ans.value();
			else
				throw err::InvalidArgumentValueException(argVals[0]);
		}
		else if (argName == "-bg")
		{
			if (argVals.size() == 1)
				bgColor = utils::Converter::stringToColor(argVals[0]);
			else if (argVals.size() == 3)
				bgColor = utils::Converter::vectorToColor(argVals);
			else
				throw err::InvalidArgumentValueException("'-bg' takes 1 or 3 values");
			if (!bgColor)
				throw err::InvalidArgumentValueException("Invalid color");
		}
		else
			throw err::InvalidArgumentException(argName);
	}
	return std::make_unique<cmds::AddSlideCommand>(at, bgColor);
}