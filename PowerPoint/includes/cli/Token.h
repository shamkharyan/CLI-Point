#pragma once

#include <string>

namespace ppt::cli
{
	struct Token
	{
		enum class Type { String, Word, Comma, EOL, Error };
		Type type;
		std::string value;
	};
}
