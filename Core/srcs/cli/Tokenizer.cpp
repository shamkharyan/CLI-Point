#include "cli/Tokenizer.h"

#include <string>
#include <istream>
#include <optional>

using namespace ppt::cli;

Tokenizer::Tokenizer(std::istream& is) : m_is(is), m_error(false), m_eol(false) {}

bool Tokenizer::isError() const noexcept
{
	return m_error;
}

bool Tokenizer::isEOL() const noexcept
{
	return m_eol;
}

Token Tokenizer::getNextToken()
{
	if (isError())
		return { Token::Type::Error, "" };

	if (isEOL())
		return { Token::Type::EOL, "\n" };

	char c;

	while (m_is.get(c))
	{
		if (c == '\n')
			return eolReturn();
		if (!std::isspace(c))
			break;
	}

	if (c == '"')
		return getStringToken();

	if (c == ',')
		return {Token::Type::Comma, ","};

	m_is.unget();
	return getToken();
}

Token Tokenizer::getStringToken()
{
	char c;
	std::string token;
	bool closed = false;

	while (m_is.get(c))
	{
		if (c == '\\' && m_is.peek() == '"')
		{
			m_is.get(c);
			token.push_back(c);
			continue;
		}
		if (c == '"')
		{
			closed = true;
			break;
		}
		if (c == '\n')
		{
			m_is.unget();
			break;
		}
		token.push_back(c);
	}

	if (!closed)
		return errorReturn();

	int next = m_is.peek();
	if (next != EOF &&
		next != ',' &&
		!std::isspace(next) &&
		next != '\n')
		return errorReturn();

	return { Token::Type::String, token };
}

Token Tokenizer::getToken()
{
	char c;
	std::string token;

	while (m_is.get(c))
	{
		if (c == ',' || isspace(c))
		{
			if (c == ',' || c == '\n')
				m_is.unget();
			break;
		}
		if (!isalnum(c) && c != '_' && c != '-')
			return errorReturn();
		token.push_back(c);
	}

	if (token.empty())
		return eolReturn();

	return { Token::Type::Word, token };
}

Token Tokenizer::errorReturn() noexcept
{
	m_error = true;
	return {Token::Type::Error, ""};
}

Token Tokenizer::eolReturn() noexcept
{
	m_eol = true;
	return { Token::Type::EOL, "\n" };
}

void Tokenizer::reset() noexcept
{
	m_eol = false;
	m_error = false;
}