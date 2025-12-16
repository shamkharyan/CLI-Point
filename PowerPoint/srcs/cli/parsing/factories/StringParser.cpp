#include "cli/parsing/factories/StringFactory.h"

#include <stdexcept>

using namespace ppt::cli;

bool StringFactory::canCreate(const std::vector<std::string>& argValue) const
{
	return argValue.size() == 1;
}

ArgValue StringFactory::create(const std::vector<std::string>& argValue) const
{
	if (!canCreate(argValue))
		throw std::invalid_argument("Multiple string values are not allowed");

	return argValue[0];
}

std::string StringFactory::typeName() const
{
	return argValueTypeName(std::string{});
}
