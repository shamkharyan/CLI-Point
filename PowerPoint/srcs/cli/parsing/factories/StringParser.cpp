#include "cli/parsing/factories/StringFactory.h"

#include <stdexcept>

using namespace ppt::cli;

std::optional<ArgValue> StringFactory::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;
	return argValue[0];
}

std::string StringFactory::typeName() const
{
	return "string";
}