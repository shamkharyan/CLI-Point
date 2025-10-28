#pragma once

#include "core/factories/AConfirmCommandFactory.h"

#include <string>

namespace ppt::core::factories
{
  class CreatePresentationCommandFactory : public AConfirmCommandFactory
  {
  public:
    CreatePresentationCommandFactory(model::AppContext& context, viewer::IViewer& viewer) :
      AConfirmCommandFactory(context, viewer) {}

    std::unique_ptr<cmds::ACommand> createCommand(const Arguments& args) override;
  };
}
