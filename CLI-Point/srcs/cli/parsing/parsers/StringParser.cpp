#include "cli/parsing/parsers/StringParser.h"

#include <stdexcept>

using namespace ppt::cli;

std::optional<ArgValue> StringParser::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;
	return ArgValue(argValue[0]);
}

std::string StringParser::typeName() const
{
	return "string";
}