#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"

class Command
{
public:
	Command(AppContext& context, IViewer& viewer) : m_context(context), m_viewer(viewer) {}
	virtual ~Command() = default;

	virtual void execute() = 0;
protected:
	AppContext& m_context;
	IViewer& m_viewer;
};
