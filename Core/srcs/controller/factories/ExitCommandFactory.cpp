#include "controller/factories/ExitCommandFactory.h"

#include "controller/commands/ACommand.h"
#include "controller/commands/ExitCommand.h"
#include "controller/factories/errors/InvalidArgumentException.h"
#include "controller/factories/errors/InvalidArgumentValueException.h"

#include <memory>
#include <stdexcept>

std::unique_ptr<ACommand> ExitCommandFactory::createCommand(const Arguments& args)
{
  bool force = false;

  for (const auto& arg : args)
  {
    const auto& argName = arg.first;
    const auto& argVals = arg.second;
    if (argName == "-f")
    {
      if (!argVals.empty())
        throw InvalidArgumentValueException(arg.second[0]);
      force = true;
    }
    else
      throw InvalidArgumentException(argName);
  }
  return std::make_unique<ExitCommand>(m_context, m_viewer, force);
}