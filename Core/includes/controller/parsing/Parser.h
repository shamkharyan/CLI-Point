#pragma once

#include "model/AppContext.h"
#include "controller/parsing/Tokenizer.h"
#include "AllCommands.h"
#include "viewer/CLIViewer.h"

#include <memory>

class Parser
{
public:
	Parser(AppContext& context, std::istream& istream);

	std::unique_ptr<Command> parse();
private:
	Tokenizer m_tokenizer;
	AppContext& m_context;
	std::istream& m_istream;
};
