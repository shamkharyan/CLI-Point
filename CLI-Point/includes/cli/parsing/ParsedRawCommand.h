#pragma once

#include "cli/parsing/parsers/ArgValue.h"

#include <string>
#include <unordered_map>

namespace ppt::cli
{
	struct ParsedRawCommand
	{
		std::string name;
		std::unordered_map<std::string, ArgValue> arguments;
	};
}
