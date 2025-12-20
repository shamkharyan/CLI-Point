#include "cli/parsing/parsers/BoolParser.h"

#include <stdexcept>

using namespace ppt::cli;

std::optional<ArgValue> BoolParser::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() > 1)
		return std::nullopt;

	if (argValue.empty())
		return ArgValue(true);

	const std::string& val = argValue[0];
	if (val == "true" || val == "1")
		return ArgValue(true);
	if (val == "false" || val == "0")
		return ArgValue(false);

	return std::nullopt;
}

std::string BoolParser::typeName() const
{
	return "bool";
}
