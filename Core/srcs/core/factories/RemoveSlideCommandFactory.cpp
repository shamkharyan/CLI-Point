#include "core/factories/RemoveSlideCommandFactory.h"
#include "core/commands/RemoveSlideCommand.h"
#include "core/errors/InvalidArgumentException.h"
#include "core/errors/InvalidArgumentValueException.h"
#include "core/errors/MissingArgumentException.h"
#include "utils/Converter.h"

using namespace ppt::core;
using namespace ppt::core::factories;

std::unique_ptr<cmds::ACommand> RemoveSlideCommandFactory::createCommand(const Arguments& args)
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
    if (!at)
        throw err::MissingArgumentException("-at");
    return std::make_unique<cmds::RemoveSlideCommand>(m_context, at.value());
}