#pragma once

#include "cli/Tokenizer.h"
#include "cli/commands/ICommand.h"
#include "viewer/cli/CLIViewer.h"

#include <memory>

//                              DFA of Parser
// -----------------------------------------------------------------------
// | State/Token | Command |   EOL   | Argument | Value  |   ,   | Other |
// -----------------------------------------------------------------------
// |    Empty    | Command | Empty   | Error    | Error  | Error | Error | 
// -----------------------------------------------------------------------
// |   Command   | Error   | Success | ArgName  | Error  | Error | Error |
// -----------------------------------------------------------------------
// |   ArgName   | Error   | Success | ArgName  | ArgVal | Error | Error |
// -----------------------------------------------------------------------
// |   ArgVal    | Error   | Success | ArgName  | Error  | Comma | Error |
// -----------------------------------------------------------------------
// |    Comma    | Error   | Error   | Error    | ArgVal | Error | Error |
// -----------------------------------------------------------------------
// |    Error    | Error   | Error   | Error    | Error  | Error | Error |
// -----------------------------------------------------------------------
// |   Success   | Error   | Success | Error    | Error  | Error | Error |
// -----------------------------------------------------------------------

namespace ppt::cli
{
	class Parser
	{
	public:
		Parser(CommandRegistry& registry, std::istream& istream);
		std::unique_ptr<cmds::ICommand> parse();
	private:
		enum class State { Empty, Command, ArgName, ArgVal, Comma, Success };
	private:
		bool isArgName(Token tok) const;
		bool isArgVal(Token tok) const;

		void processCommandState(const Token& tok, State& st, factories::Arguments& args, std::string& currArgName, const std::string& cmdName);
		void processArgNameState(const Token& tok, State& st, factories::Arguments& args, std::string& currArgName, const std::string& cmdName);
		void processArgValState(const Token& tok, State& st, factories::Arguments& args, std::string& currArgName, const std::string& cmdName);
		void processCommaState(const Token& tok, State& st, factories::Arguments& args, std::string& currArgName);
	private:
		Tokenizer m_tokenizer;
		CommandRegistry& m_registry;
		std::istream& m_istream;
	};
}
