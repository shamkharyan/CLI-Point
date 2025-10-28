#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/factories/ExitCommandFactory.h"
#include "core/commands/ExitCommand.h"

using namespace ppt;
using namespace ppt::cli::factories;

std::unique_ptr<core::cmds::ICommand> ExitCommandFactory::createCommand(const Arguments& args)
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
  return std::make_unique<core::cmds::ExitCommand>(m_viewer, force);
}