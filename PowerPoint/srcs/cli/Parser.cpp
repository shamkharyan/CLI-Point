#include "cli/CommandRegistry.h"
#include "cli/errors/InvalidInputException.h"
#include "cli/errors/UnknownCommandException.h"
#include "cli/errors/InvalidArgumentException.h"
#include "cli/factories/ICommandFactory.h"
#include "cli/Parser.h"
#include "cli/Tokenizer.h"

#include <unordered_set>

using namespace ppt::cli;

Parser::Parser(CommandRegistry& registry, std::istream& istream) :
	m_registry(registry),
	m_istream(istream),
	m_tokenizer(istream)
{
}

std::unique_ptr<cmds::ICommand> Parser::parse()
{
	State st = State::Empty;
	m_tokenizer.reset();

	Token cmdName = m_tokenizer.getNextToken();
	if (cmdName.type == Token::Type::EOL)
		return nullptr;
	if (cmdName.type != Token::Type::Word)
		throw err::InvalidInputException("Invalid command syntax");

	auto factory = m_registry.getFactory(cmdName.value);
	if (!factory)
		throw err::UnknownCommandException(cmdName.value);

	factories::Arguments args;
	std::string currArgName;
	st = State::Command;

	while (st != State::Success)
	{
		Token tok = m_tokenizer.getNextToken();
		switch (st)
		{
		case State::Command:
			processCommandState(tok, st, args, currArgName, cmdName.value);
			break;
		case State::ArgName:
			processArgNameState(tok, st, args, currArgName, cmdName.value);
			break;
		case State::ArgValue:
			processArgValueState(tok, st, args, currArgName, cmdName.value);
			break;
		case State::Comma:
			processCommaState(tok, st, args, currArgName);
			break;
		default:
			throw err::InvalidInputException("Unknown Error");
		}
	}

	return factory->createCommand(args);
}

bool Parser::isArgName(Token tok) const
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

bool Parser::isArgValue(Token tok) const
{
	if (tok.type != Token::Type::Word &&
		tok.type != Token::Type::String)
		return false;

	return !isArgName(tok);
}

void Parser::processCommandState(const Token& tok, State& st, factories::Arguments& args, std::string& currArgName, const std::string& cmdName)
{
	if (isArgName(tok))
	{
		if (!m_registry.getMeta(cmdName)->supportsArgument(tok.value))
			throw err::InvalidArgumentException(cmdName);
		currArgName = tok.value;
		args[currArgName] = {};
		st = State::ArgName;
	}
	else if (tok.type == Token::Type::EOL)
		st = State::Success;
	else
		throw err::InvalidInputException("Expecting argument or EOL after command");
}

void Parser::processArgNameState(const Token& tok, State& st, factories::Arguments& args, std::string& currArgName, const std::string& cmdName)
{
	if (isArgName(tok))
	{
		if (!m_registry.getMeta(cmdName)->supportsArgument(tok.value))
			throw err::InvalidArgumentException(cmdName);
		currArgName = tok.value;
		args[currArgName] = {};
	}
	else if (isArgValue(tok))
	{
		args[currArgName].push_back(tok.value);
		st = State::ArgValue;
	}
	else if (tok.type == Token::Type::EOL)
		st = State::Success;
	else
		throw err::InvalidInputException("Expecting argument, value or EOL after argument");
}

void Parser::processArgValueState(const Token& tok, State& st, factories::Arguments& args, std::string& currArgName, const std::string& cmdName)
{
	if (isArgName(tok))
	{
		if (!m_registry.getMeta(cmdName)->supportsArgument(tok.value))
			throw err::InvalidArgumentException(cmdName);
		currArgName = tok.value;
		args[currArgName] = {};
		st = State::ArgName;
	}
	else if (tok.type == Token::Type::Comma)
		st = State::Comma;
	else if (tok.type == Token::Type::EOL)
		st = State::Success;
	else
		throw err::InvalidInputException("Expecting argument, comma or EOL after value");
}

void Parser::processCommaState(const Token& tok, State& st, factories::Arguments& args, std::string& currArgName)
{
	if (isArgValue(tok))
	{
		args[currArgName].push_back(tok.value);
		st = State::ArgValue;
	}
	else
		throw err::InvalidInputException("Expecting value after comma");
}