#include "cli/parsing/parsers/FloatParser.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

std::optional<ArgValue> FloatParser::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;

	try
	{
		return ArgValue(std::stof(argValue[0]));
	}
	catch (...) {}

	return std::nullopt;
}

std::string FloatParser::typeName() const
{
	return "float";
}
