#pragma once

#include "cli/parsing/ArgValue.h"

#include <string>
#include <unordered_map>

struct ValidatedRawCommand
{
	std::string name;
	std::unordered_map<std::string, ArgValue> arguments;
};
