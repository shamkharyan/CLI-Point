#include "cli/parsing/SyntaxParser.h"
#include "cli/parsing/errors/SyntaxException.h"

using namespace ppt::cli;

SyntaxParser::SyntaxParser(std::istream& istream) :
	m_istream(istream),
	m_tokenizer(istream)
{
}

RawCommand SyntaxParser::parse()
{
	State st = State::Empty;
	m_tokenizer.reset();

	Token cmdName = m_tokenizer.getNextToken();
	if (cmdName.type == Token::Type::EOL)
		return {};
	if (cmdName.type != Token::Type::Word)
		throw SyntaxException("Invalid command syntax");

	RawCommand rcmd;
	rcmd.name = cmdName.value;

	std::string currArgName;
	st = State::Command;

	while (st != State::Success)
	{
		Token tok = m_tokenizer.getNextToken();
		switch (st)
		{
		case State::Command:
			processCommandState(tok, st, rcmd, currArgName, cmdName.value);
			break;
		case State::ArgName:
			processArgNameState(tok, st, rcmd, currArgName, cmdName.value);
			break;
		case State::ArgValue:
			processArgValueState(tok, st, rcmd, currArgName, cmdName.value);
			break;
		case State::Comma:
			processCommaState(tok, st, rcmd, currArgName);
			break;
		default:
			throw SyntaxException("Unknown Error");
		}
	}
	return rcmd;
}

bool SyntaxParser::isArgName(Token tok) const
{
	if (tok.type != Token::Type::Word ||
		tok.value.size() < 2 ||
		tok.value[0] != '-')
		return false;

	std::size_t i = (tok.value[1] == '-') ? 2 : 1;
	std::size_t n = tok.value.size();

	if (i == n)
		return false;

	for (; i < n; ++i)
	{
		if (!std::isalpha(tok.value[i]) && tok.value[i] != '-')
			return false;
	}
	return true;
}

bool SyntaxParser::isArgValue(Token tok) const
{
	if (tok.type != Token::Type::Word &&
		tok.type != Token::Type::String)
		return false;

	return !isArgName(tok);
}

void SyntaxParser::processCommandState(
	const Token& tok, State& st, 
	RawCommand& rcmd, 
	std::string& currArgName, 
	const std::string& cmdName)
{
	if (isArgName(tok))
	{
		currArgName = tok.value;
		rcmd.arguments[currArgName] = {};
		st = State::ArgName;
	}
	else if (tok.type == Token::Type::EOL)
		st = State::Success;
	else
		throw SyntaxException("Expecting argument or EOL after command");
}

void SyntaxParser::processArgNameState(
	const Token& tok, 
	State& st,
	RawCommand& rcmd,
	std::string& currArgName,
	const std::string& cmdName)
{
	if (isArgName(tok))
	{
		currArgName = tok.value;
		rcmd.arguments[currArgName] = {};
	}
	else if (isArgValue(tok))
	{
		rcmd.arguments[currArgName].push_back(tok.value);
		st = State::ArgValue;
	}
	else if (tok.type == Token::Type::EOL)
		st = State::Success;
	else
		throw SyntaxException("Expecting argument, value or EOL after argument");
}

void SyntaxParser::processArgValueState(
	const Token& tok, State& st,
	RawCommand& rcmd,
	std::string& currArgName,
	const std::string& cmdName)
{
	if (isArgName(tok))
	{
		currArgName = tok.value;
		rcmd.arguments[currArgName] = {};
		st = State::ArgName;
	}
	else if (tok.type == Token::Type::Comma)
		st = State::Comma;
	else if (tok.type == Token::Type::EOL)
		st = State::Success;
	else
		throw SyntaxException("Expecting argument, comma or EOL after value");
}

void SyntaxParser::processCommaState(
	const Token& tok,
	State& st, 
	RawCommand& rcmd, 
	std::string& currArgName)
{
	if (isArgValue(tok))
	{
		rcmd.arguments[currArgName].push_back(tok.value);
		st = State::ArgValue;
	}
	else
		throw SyntaxException("Expecting value after comma");
}

