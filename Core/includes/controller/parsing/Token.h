#pragma once

#include <string>

struct Token
{
	enum class Type
	{
		String,
		Word,
		Comma,
		EOL,
		Error
	};
	Type type;
	std::string value;
};
