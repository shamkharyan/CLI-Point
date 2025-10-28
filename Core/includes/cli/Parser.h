#pragma once

#include "model/AppContext.h"
#include "cli/Tokenizer.h"
#include "core/commands/ICommand.h"
#include "viewer/cli/CLIViewer.h"

#include <memory>

//                              DFA of Parser
// -----------------------------------------------------------------------
// | State/Input | Command |   EOL   | Argument | Value  |   ,   | Other |
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
		Parser(std::istream& istream);
		std::unique_ptr<core::cmds::ICommand> parse();
	private:
		enum class State { Empty, Command, ArgName, ArgVal, Comma, Error, Success };
	private:
		bool isArgName(Token tok) const;
		bool isArgVal(Token tok) const;
	private:
		Tokenizer m_tokenizer;
		std::istream& m_istream;
	};
}
