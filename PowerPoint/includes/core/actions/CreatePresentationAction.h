#pragma once

#include "viewer/IViewer.h"
#include "core/actions/IAction.h"
#include "model/utils/Color.h"
#include "model/Presentation.h"

#include <string>

namespace ppt::core::act
{
  class CreatePresentationAction : public IAction
  {
  public:
    CreatePresentationAction(viewer::IViewer& viewer, const std::string& name) : 
      m_name(name),
      m_viewer(viewer)
    {}

    void doAction() override;
    void undoAction() override;
  private:
    std::shared_ptr<model::Presentation> m_oldPresentation;
    std::string m_name;
    viewer::IViewer& m_viewer;
    bool m_completed = false;
  };
}
