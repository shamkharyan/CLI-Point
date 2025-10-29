#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/InvalidArgumentValueException.h"
#include "cli/errors/MissingArgumentValueException.h"
#include "cli/factories/CreatePresentationCommandFactory.h"
#include "cli/commands/CreatePresentationCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> CreatePresentationCommandFactory::createCommand(const Arguments& args)
{
  std::string name = "Untitled";

  for (const auto& [argName, argVals] : args)
  {
    if (argName == "-n")
    {
      if (argVals.size() < 1)
        throw err::MissingArgumentValueException(argName);
      if (argVals.size() > 1)
        throw err::InvalidArgumentValueException(argVals[1]);
      name = argVals[0];
    }
    else
      throw err::InvalidArgumentException(argName);
  }
  return std::make_unique<cmds::CreatePresentationCommand>(m_viewer, name);
}

