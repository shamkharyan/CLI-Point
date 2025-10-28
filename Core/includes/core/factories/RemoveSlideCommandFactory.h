#pragma once

#include "core/factories/ACommandFactory.h"

#include <string>

namespace ppt::core::factories
{
  class RemoveSlideCommandFactory : public ACommandFactory
  {
  public:
    RemoveSlideCommandFactory(model::AppContext& context) :
      ACommandFactory(context)
    {}

    std::unique_ptr<cmds::ACommand> createCommand(const Arguments& args) override;
  };
}
