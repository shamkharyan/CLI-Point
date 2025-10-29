#pragma once

#include "cli/factories/ICommandFactory.h"
#include "cli/commands/ICommand.h"

#include <string>

namespace ppt::cli::factories
{
  class AddSlideCommandFactory : public ICommandFactory
  {
  public:
      AddSlideCommandFactory() = default;
      std::unique_ptr<cmds::ICommand> createCommand(const Arguments& args) override;
  };
}
