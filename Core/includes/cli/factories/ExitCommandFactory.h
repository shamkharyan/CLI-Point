#pragma once

#include "cli/factories/ICommandFactory.h"
#include "viewer/IViewer.h"

namespace ppt::cli::factories
{
  class ExitCommandFactory : public ICommandFactory
  {
  public:
    ExitCommandFactory(viewer::IViewer& viewer) : m_viewer(viewer) {}
    std::unique_ptr<core::cmds::ICommand> createCommand(const Arguments& args) override;
  private:
      viewer::IViewer& m_viewer;
  };
}
