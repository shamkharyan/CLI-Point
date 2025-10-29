#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/RedoCommand.h"
#include "viewer/IViewer.h"
#include "core/IController.h"
#include "cli/errors/InvalidArgumentException.h"

namespace ppt::cli::factories
{
  class RedoCommandFactory : public ICommandFactory
  {
  public:
    RedoCommandFactory() = default;
    std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override
    {
      if (!args.empty())
        throw err::InvalidArgumentException(args.begin()->first);
      return std::make_unique<cmds::RedoCommand>();
    }
  };
}
