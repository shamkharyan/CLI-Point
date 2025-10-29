#pragma once

#include "viewer/IViewer.h"
#include "core/actions/IAction.h"
#include "model/utils/Color.h"
#include "model/Presentation.h"

#include <string>

namespace ppt::core::act
{
  class EditPresentationAction : public IAction
  {
  public:
    EditPresentationAction(const std::optional<std::string>& name) :
      m_name(name)
    {}

    void doAction() override;
    void undoAction() override;
  private:
    std::optional<std::string> m_oldName;
    std::optional<std::string> m_name;
  };
}
