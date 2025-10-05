#pragma once

#include <istream>
#include <string>
#include <optional>

class Tokenizer
{
public:
	Tokenizer(std::istream& is);

	std::optional<std::string> getNextToken();

	bool fail() const noexcept;
	void resetStream();
private:
	std::optional<std::string> getStringToken();
	std::optional<std::string> getToken();
	std::nullopt_t failReturn() noexcept;
private:
	std::istream& m_is;
	bool m_fail;
};
