#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentException.h"
#include "cli/factories/RemoveSlideCommandFactory.h"
#include "cli/utils/Converter.h"
#include "cli/commands/RemoveSlideCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> RemoveSlideCommandFactory::createCommand(const Arguments& args)
{
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
        else
            throw err::InvalidArgumentException(argName);
    }
    return std::make_unique<cmds::RemoveSlideCommand>(at);
}