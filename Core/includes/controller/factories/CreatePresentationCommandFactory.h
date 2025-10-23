#pragma once

#include "controller/factories/AConfirmCommandFactory.h"

#include <string>

class CreatePresentationCommandFactory : public AConfirmCommandFactory
{
public:
  CreatePresentationCommandFactory(AppContext& context, IViewer& viewer) :
    AConfirmCommandFactory(context, viewer) {}

  std::unique_ptr<ACommand> createCommand(const Arguments& args) override;
};
