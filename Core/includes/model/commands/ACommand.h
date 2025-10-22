#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"

class ACommand
{
public:
	ACommand(AppContext& context) : m_context(context) {}
	virtual ~ACommand() = default;

	virtual void execute() = 0;
protected:
	AppContext& m_context;
};
