#pragma once

#include "cli/commands/ICommand.h"
#include "cli/meta/CommandRegistry.h"
#include "cli/parsing/SyntaxParser.h"
#include "cli/parsing/SemanticParser.h"

#include <istream>
#include <memory>

namespace ppt::cli
{
	class CommandParser
	{
	public:
		CommandParser(const CommandRegistry& commandRegistry, std::istream& istream);

		std::unique_ptr<cmds::ICommand> parseCommand();
	private:
		const CommandRegistry& m_commandRegistry;
		std::istream& m_istream;
		SyntaxParser m_syntaxParser;
		SemanticParser m_semanticParser;
	};
}
