#pragma once

#include "viewer/IViewer.h"
#include "controller/commands/ACommand.h"

class AConfirmCommand : public ACommand
{
public:
	AConfirmCommand(AppContext& context, IViewer& viewer) : ACommand(context), m_viewer(viewer) {}
	virtual ~AConfirmCommand() = default;
protected:
	IViewer& m_viewer;
};
