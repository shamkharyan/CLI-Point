#pragma once

#include "viewer/cli/CLIViewer.h"
#include "cli/CLIController.h"

namespace ppt::cli
{
  void registerCommands(viewer::cli::CLIViewer& viewer, CLIController& controller);
}
