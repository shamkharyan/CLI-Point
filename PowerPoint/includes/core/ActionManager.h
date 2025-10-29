#pragma once

#include "core/actions/IAction.h"

#include <vector>
#include <memory>

namespace ppt::core
{
  class ActionManager
  {
  public:
    ActionManager() = default;
    void append(std::unique_ptr<act::IAction> action);
    void undo();
    void redo();
  private:
    std::vector<std::unique_ptr<act::IAction>> m_undo;
    std::vector<std::unique_ptr<act::IAction>> m_redo;
  };
}
