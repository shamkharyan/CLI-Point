#include "cli/factories/AddSlideCommandFactory.h"
#include "core/commands/AddSlideCommand.h"
#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"
#include "cli/utils/Converter.h"

using namespace ppt;
using namespace ppt::cli::factories;

std::unique_ptr<core::cmds::ICommand> AddSlideCommandFactory::createCommand(const Arguments& args)
{
    model::utils::Color bgColor(255, 255, 255);
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
            std::optional<model::utils::Color> ans;
            if (argVals.size() == 1)
                ans = utils::Converter::stringToColor(argVals[0]);
            else if (argVals.size() == 3)
                ans = utils::Converter::vectorToColor(argVals);
            else
                throw err::InvalidArgumentValueException("'-bg' takes 1 or 3 values");
            if (!ans)
                throw err::InvalidArgumentValueException("Invalid color");
            bgColor = ans.value();
        }
        else 
            throw err::InvalidArgumentException(argName);
    }
    return std::make_unique<core::cmds::AddSlideCommand>(at, bgColor);
}