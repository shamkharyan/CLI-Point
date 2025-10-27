#include "controller/factories/RemoveSlideCommandFactory.h"
#include "controller/commands/RemoveSlideCommand.h"
#include "controller/factories/errors/InvalidArgumentException.h"
#include "controller/factories/errors/InvalidArgumentValueException.h"
#include "controller/factories/errors/MissingArgumentException.h"
#include "controller/utils/Converter.h"

std::unique_ptr<ACommand> RemoveSlideCommandFactory::createCommand(const Arguments& args)
{
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
        else
            throw InvalidArgumentException(argName);
    }
    if (!at)
        throw MissingArgumentException("-at");
    return std::make_unique<RemoveSlideCommand>(m_context, at.value());
}