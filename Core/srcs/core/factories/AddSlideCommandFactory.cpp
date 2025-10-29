#include "core/factories/AddSlideCommandFactory.h"
#include "core/commands/AddSlideCommand.h"
#include "core/errors/InvalidArgumentException.h"
#include "core/errors/InvalidArgumentValueException.h"
#include "core/errors/MissingArgumentValueException.h"
#include "utils/Converter.h"

using namespace ppt::core;
using namespace ppt::core::factories;

std::unique_ptr<cmds::ACommand> AddSlideCommandFactory::createCommand(const Arguments& args)
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
        else if (argName == "-bgcolor")
        {
            std::optional<model::utils::Color> ans;
            if (argVals.size() == 1)
                ans = utils::Converter::stringToColor(argVals[0]);
            else if (argVals.size() == 3)
                ans = utils::Converter::vectorToColor(argVals);
            else
                throw err::InvalidArgumentValueException("'-bgcolor' takes 1 or 3 values");
            if (!ans)
                throw err::InvalidArgumentValueException("Invalid color");
            bgColor = ans.value();
        }
        else 
            throw err::InvalidArgumentException(argName);
    }
    return std::make_unique<cmds::AddSlideCommand>(m_context, at, bgColor);
}