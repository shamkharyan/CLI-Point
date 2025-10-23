#pragma once

#include "AConfirmCommandFactory.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"

class ExitCommandFactory : public AConfirmCommandFactory
{
public:
  ExitCommandFactory(AppContext& context, IViewer& viewer) : AConfirmCommandFactory(context, viewer) {}
  std::unique_ptr<ACommand> createCommand(const Arguments& args) override;
};
