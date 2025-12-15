#pragma once

#include "cli/parsing/ArgValue.h"

#include <string>
#include <unordered_map>

namespace ppt::cli
{
	struct ValidatedRawCommand
	{
		std::string name;
		std::unordered_map<std::string, ArgValue> arguments;
	};
}
