#include "cli/parsing/parsers/SizeTParser.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

std::optional<ArgValue> SizeTParser::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;

	try
	{
		return ArgValue(std::stoull(argValue[0]));
	}
	catch (...) {}

	return std::nullopt;
}

std::string SizeTParser::typeName() const
{
	return "size_t";
}
