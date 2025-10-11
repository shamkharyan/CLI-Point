#pragma once

#include "model/AppContext.h"
#include "AllCommands.h"

#include <memory>

class Parser
{
public:
	Parser(AppContext&, std::istream&);

	std::unique_ptr<Command> parse();
	void resetStream();
private:
	AppContext& m_context;
	std::istream& m_stream;
};
