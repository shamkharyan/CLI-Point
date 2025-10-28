#pragma once

#include "cli/factories/ICommandFactory.h"
#include "core/commands/ICommand.h"

#include <string>

namespace ppt::cli::factories
{
  class AddSlideCommandFactory : public ICommandFactory
  {
  public:
      AddSlideCommandFactory() = default;
      std::unique_ptr<core::cmds::ICommand> createCommand(const Arguments& args) override;
  };
}
