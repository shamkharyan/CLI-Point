#pragma once

#include "AConfirmCommandFactory.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"

namespace ppt::core::factories
{
  class ExitCommandFactory : public AConfirmCommandFactory
  {
  public:
    ExitCommandFactory(model::AppContext& context, viewer::IViewer& viewer) : AConfirmCommandFactory(context, viewer) {}
    std::unique_ptr<cmds::ACommand> createCommand(const Arguments& args) override;
  };
}
