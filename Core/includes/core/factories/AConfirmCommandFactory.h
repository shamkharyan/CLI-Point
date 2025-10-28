#pragma once

#include "ACommandFactory.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"

namespace ppt::core::factories
{
  class AConfirmCommandFactory : public ACommandFactory
  {
  public:
    AConfirmCommandFactory(model::AppContext& context, viewer::IViewer& viewer) : ACommandFactory(context), m_viewer(viewer) {}
  protected:
    viewer::IViewer& m_viewer;
  };
}