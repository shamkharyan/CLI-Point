#pragma once

#include "ACommandFactory.h"
#include "model/AppContext.h"
#include "viewer/IViewer.h"

class AConfirmCommandFactory : public ACommandFactory
{
public:
  AConfirmCommandFactory(AppContext& context, IViewer& viewer) : ACommandFactory(context), m_viewer(viewer) {}
protected:
  IViewer& m_viewer;
};