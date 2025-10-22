#pragma once

#include "ACommand.h"
#include "viewer/IViewer.h"

class AConfirmCommand : public ACommand
{
public:
	AConfirmCommand(AppContext& context, IViewer& viewer) : ACommand(context), m_viewer(viewer) {}
	virtual ~AConfirmCommand() = default;
protected:
	IViewer& m_viewer;
};
