#pragma once

#include <istream>
#include <string>

#include "controller/parsing/Token.h"

class Tokenizer
{
public:
	Tokenizer(std::istream& is);

	Token getNextToken();

	void reset() noexcept;
	bool isError() const noexcept;
	bool isEOL() const noexcept;
private:
	Token getStringToken();
	Token getToken();
	Token errorReturn() noexcept;
	Token eolReturn() noexcept;
private:
	std::istream& m_is;
	bool m_error;
	bool m_eol;
};
