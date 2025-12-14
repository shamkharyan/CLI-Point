#pragma once

#include "Tokenizer.h"
#include "RawCommand.h"

#include <istream>
#include <string>
#include <vector>
#include <unordered_map>

//                           DFA of SytaxParser
// ------------------------------------------------------------------------
// | State     | Command |   EOL   | Argument |  Value   |   ,   | Other  |
// ------------------------------------------------------------------------
// | Empty     | Command | Empty   | Error    | Error    | Error | Error  |
// ------------------------------------------------------------------------
// | Command   | Error   | Success | ArgName  | Error    | Error | Error  |
// ------------------------------------------------------------------------
// | ArgName   | Error   | Success | ArgName  | ArgValue | Error | Error  |
// ------------------------------------------------------------------------
// | ArgValue  | Error   | Success | ArgName  | Error    | Comma | Error  |
// ------------------------------------------------------------------------
// | Comma     | Error   | Error   | Error    | ArgValue | Error | Error  |
// ------------------------------------------------------------------------
// | Error     | Error   | Error   | Error    | Error    | Error | Error  |
// ------------------------------------------------------------------------
// | Success   | Error   | Success | Error    | Error    | Error | Error  |
// ------------------------------------------------------------------------

namespace ppt::cli
{
	class SyntaxParser
	{
	public:
		SyntaxParser(std::istream& istream);

		RawCommand parse();

	private:
		enum class State { Empty, Command, ArgName, ArgValue, Comma, Success };
	private:
		bool isArgName(Token tok) const;
		bool isArgValue(Token tok) const;

		void processCommandState(
			const Token& tok,
			State& st,
			RawCommand& rcmd,
			std::string& currArgName,
			const std::string& cmdName
		);

		void processArgNameState(
			const Token& tok,
			State& st,
			RawCommand& rcmd,
			std::string& currArgName,
			const std::string& cmdName
		);

		void processArgValueState(
			const Token& tok,
			State& st,
			RawCommand& rcmd,
			std::string& currArgName,
			const std::string& cmdName
		);

		void processCommaState(
			const Token& tok,
			State& st,
			RawCommand& rcmd,
			std::string& currArgName
		);
	private:
		std::istream& m_istream;
		Tokenizer m_tokenizer;
	};
}