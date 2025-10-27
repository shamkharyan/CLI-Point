#include "controller/factories/AddSlideCommandFactory.h"
#include "controller/commands/AddSlideCommand.h"
#include "controller/factories/errors/InvalidArgumentException.h"
#include "controller/factories/errors/InvalidArgumentValueException.h"
#include "controller/factories/errors/MissingArgumentValueException.h"
#include "controller/utils/Converter.h"

std::unique_ptr<ACommand> AddSlideCommandFactory::createCommand(const Arguments& args)
{
    Color bgColor(255, 255, 255);
	std::optional<std::size_t> at;

    for (const auto& [argName, argVals] : args)
    {
        if (argName == "-at")
        {
            if (argVals.size() != 1)
                throw InvalidArgumentValueException("'-at' takes exactly one value");
            if (auto ans = Converter::stringToSizeT(argVals[0]))
                at = ans.value();
            else
                throw InvalidArgumentValueException(argVals[0]);
        }
        else if (argName == "-bgcolor")
        {
            std::optional<Color> ans;
            if (argVals.size() == 1)
                ans = Converter::stringToColor(argVals[0]);
            else if (argVals.size() == 3)
                ans = Converter::vectorToColor(argVals);
            else
                throw InvalidArgumentValueException("'-bgcolor' takes 1 or 3 values");
            if (!ans)
                throw InvalidArgumentValueException("Invalid color");
            bgColor = ans.value();
        }
        else 
            throw InvalidArgumentException(argName);
    }
    return std::make_unique<AddSlideCommand>(m_context, at, bgColor);
}