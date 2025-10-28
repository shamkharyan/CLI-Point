#include "cli/Parser.h"
#include "cli/Tokenizer.h"
#include "core/factories/ACommandFactory.h"
#include "core/CommandRegistry.h"
#include "cli/errors/UnknownCommandException.h"
#include "cli/errors/InvalidInputException.h"

#include <unordered_set>

using namespace ppt::core;
using namespace ppt::cli;

Parser::Parser(std::istream& istream) : 
	m_istream(istream),
	m_tokenizer(istream)
{ }

std::unique_ptr<cmds::ACommand> Parser::parse()
{
	State st = State::Empty;
	auto& registry = CommandRegistry::instance();
	m_tokenizer.reset();

	auto cmdName = m_tokenizer.getNextToken();
	if (cmdName.type == Token::Type::EOL)
		return nullptr;
	if (cmdName.type != Token::Type::Word)
		throw err::InvalidInputException("Invalid command syntax");

	std::shared_ptr<factories::ACommandFactory> factory = registry.getFactory(cmdName.value);
	if (!factory)
		throw err::UnknownCommandException(cmdName.value);

	factories::Arguments args;
	std::string currArgName;
	std::string errMsg;
	st = State::Command;

	while (st != State::Success && st != State::Error)
	{
		Token tok = m_tokenizer.getNextToken();
		if (st == State::Command)
		{
			if (isArgName(tok))
			{
				currArgName = tok.value;
				args[currArgName] = {};
				st = State::ArgName;
			}
			else if (tok.type == Token::Type::EOL)
			{
				st = State::Success;
			}
			else
			{
				st = State::Error;
				errMsg = "Expecting argument or EOL after command";
			}
		}
		else if (st == State::ArgName)
		{
			if (isArgName(tok))
			{
				currArgName = tok.value;
				args[currArgName] = {};
			}
			else if (isArgVal(tok))
			{
				args[currArgName].push_back(tok.value);
				st = State::ArgVal;
			}
			else if (tok.type == Token::Type::EOL)
			{
				st = State::Success;
			}
			else
			{
				st = State::Error;
				errMsg = "Expecting argument, value or EOL after argument";
			}
		}
		else if (st == State::ArgVal)
		{
			if (isArgName(tok))
			{
				currArgName = tok.value;
				args[currArgName] = {};
				st = State::ArgName;
			}
			else if (tok.type == Token::Type::Comma)
			{
				st = State::Comma;
			}
			else if (tok.type == Token::Type::EOL)
			{
				st = State::Success;
			}
			else
			{
				st = State::Error;
				errMsg = "Expecting argument, comma or EOL after value";
			}
		}
		else if (st == State::Comma)
		{
			if (isArgVal(tok))
			{
				args[currArgName].push_back(tok.value);
				st = State::ArgVal;
			}
			else
			{
				st = State::Error;
				errMsg = "Expecting value after comma";
			}
		}
		else
		{
			st = State::Error;
			errMsg = "Unknown Error";
		}
	}

	if (st == State::Error)
		throw err::InvalidInputException(errMsg.c_str());

	return factory->createCommand(args);
}

bool Parser::isArgName(Token tok) const
{
	if (tok.type != Token::Type::Word ||
			tok.value.empty() ||
			tok.value[0] != '-')
		return false;

	std::size_t n = tok.value.size();
	for (std::size_t i = 1; i < n; ++i)
	{
		if (!std::isalpha(tok.value[i]))
			return false;
	}
	return true;
}

bool Parser::isArgVal(Token tok) const
{
	if (tok.type != Token::Type::Word &&
			tok.type != Token::Type::String)
		return false;

	return !isArgName(tok);
}