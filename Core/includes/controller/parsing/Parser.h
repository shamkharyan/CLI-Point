#pragma once

#include "model/AppContext.h"
#include "controller/parsing/Tokenizer.h"
#include "model/commands/ACommand.h"
#include "viewer/CLIViewer.h"

#include <memory>

class Parser
{
public:
	Parser(AppContext& context, std::istream& istream);

	std::unique_ptr<ACommand> parse();
private:
	Tokenizer m_tokenizer;
	AppContext& m_context;
	std::istream& m_istream;
};
