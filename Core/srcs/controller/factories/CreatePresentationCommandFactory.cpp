#include "controller/factories/CreatePresentationCommandFactory.h"
#include "controller/commands/CreatePresentationCommand.h"
#include "controller/factories/errors/InvalidArgumentException.h"
#include "controller/factories/errors/MissingArgumentValueException.h"
#include "controller/factories/errors/InvalidArgumentValueException.h"

std::unique_ptr<ACommand> CreatePresentationCommandFactory::createCommand(const Arguments& args)
{
  std::string name = "Untitled";

  for (const auto& arg : args)
  {
    const auto& argName = arg.first;
    const auto& argVals = arg.second;
    if (argName == "-name")
    {
      if (argVals.size() < 1)
        throw MissingArgumentValueException(argName);
      if (argVals.size() > 1)
        throw InvalidArgumentValueException(argVals[1]);
      name = argVals[0];
    }
    else
      throw InvalidArgumentException(argName);
  }
  return std::make_unique<CreatePresentationCommand>(m_context, m_viewer, name);
}

