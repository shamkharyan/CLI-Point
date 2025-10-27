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

  for (const auto& [argName, argVals] : args)
  {
    if (argName == "-f")
    {
      if (!argVals.empty())
        throw InvalidArgumentValueException(argVals[0]);
      force = true;
    }
    else
      throw InvalidArgumentException(argName);
  }
  return std::make_unique<ExitCommand>(m_context, m_viewer, force);
}