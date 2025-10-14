#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"

class Command
{
public:
	enum class Result
	{
		Success,
		Confirmation,
		Fail
	};
public:
	Command(AppContext& context) : m_context(context) {}
	virtual ~Command() = default;

	virtual Result execute() = 0;
protected:
	AppContext& m_context;
};
