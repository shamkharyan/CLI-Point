#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"

class ACommand
{
public:
	enum class Result
	{
		Success,
		Confirmation,
		Fail
	};
public:
	ACommand(AppContext& context) : m_context(context) {}
	virtual ~ACommand() = default;

	virtual Result execute() = 0;
protected:
	AppContext& m_context;
};
