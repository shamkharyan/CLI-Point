#include "Tokenizer.h"

#include <string>
#include <istream>
#include <optional>

Tokenizer::Tokenizer(std::istream& is) : m_is(is), m_fail(false) {}

bool Tokenizer::fail() const noexcept { return m_fail; }

std::nullopt_t Tokenizer::failReturn() noexcept
{
	m_fail = true;
	return std::nullopt;
}

std::optional<std::string> Tokenizer::getNextToken()
{
	char c;

	while (m_is.get(c))
	{
		if (c == '\n')
			return std::nullopt;
		if (!std::isspace(c))
			break;
	}

	if (c == '"')
		return getStringToken();

	if (c == ',')
		return ",";

	m_is.unget();
	return getToken();
}

std::optional<std::string> Tokenizer::getStringToken()
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
		return failReturn();

	int next = m_is.peek();
	if (next != EOF &&
		next != ',' &&
		!std::isspace(next) &&
		next != '\n')
		return failReturn();

	return token;
}

std::optional<std::string> Tokenizer::getToken()
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
			return failReturn();
		token.push_back(c);
	}

	if (token.empty())
		return std::nullopt;

	return token;
}

void Tokenizer::resetStream()
{
	m_is.clear();
	m_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	m_fail = false;
}