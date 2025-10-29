#include "core/factories/CreatePresentationCommandFactory.h"
#include "core/commands/CreatePresentationCommand.h"
#include "core/errors/InvalidArgumentException.h"
#include "core/errors/MissingArgumentValueException.h"
#include "core/errors/InvalidArgumentValueException.h"

using namespace ppt::core;
using namespace ppt::core::factories;

std::unique_ptr<cmds::ACommand> CreatePresentationCommandFactory::createCommand(const Arguments& args)
{
  std::string name = "Untitled";

  for (const auto& [argName, argVals] : args)
  {
    if (argName == "-name")
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
  return std::make_unique<cmds::CreatePresentationCommand>(m_context, m_viewer, name);
}

