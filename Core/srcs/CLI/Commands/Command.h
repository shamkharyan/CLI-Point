#pragma once

#include "model/AppContext.h"

class Command
{
public:
	Command(AppContext& context) : m_context(context) {}
	virtual ~Command() = default;

	virtual void execute() = 0;
protected:
	AppContext& m_context;
};
