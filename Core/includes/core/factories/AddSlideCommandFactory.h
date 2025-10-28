#pragma once

#include "core/factories/ACommandFactory.h"

#include <string>

namespace ppt::core::factories
{
  class AddSlideCommandFactory : public ACommandFactory
  {
  public:
    AddSlideCommandFactory(model::AppContext& context) :
      ACommandFactory(context) {}

    std::unique_ptr<cmds::ACommand> createCommand(const Arguments& args) override;
  };
}
