#include "core/factories/ExitCommandFactory.h"

#include "core/commands/ACommand.h"
#include "core/commands/ExitCommand.h"
#include "core/errors/InvalidArgumentException.h"
#include "core/errors/InvalidArgumentValueException.h"

#include <memory>
#include <stdexcept>

using namespace ppt::core;
using namespace ppt::core::factories;

std::unique_ptr<cmds::ACommand> ExitCommandFactory::createCommand(const Arguments& args)
{
  bool force = false;

  for (const auto& [argName, argVals] : args)
  {
    if (argName == "-f")
    {
      if (!argVals.empty())
        throw err::InvalidArgumentValueException(argVals[0]);
      force = true;
    }
    else
      throw err::InvalidArgumentException(argName);
  }
  return std::make_unique<cmds::ExitCommand>(m_context, m_viewer, force);
}