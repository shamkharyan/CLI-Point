#include "cli/parsing/factories/BoolFactory.h"

#include <stdexcept>

using namespace ppt::cli;

std::optional<ArgValue> BoolFactory::tryCreate(const std::vector<std::string>& argValue) const
{
	if (!argValue.empty())
		return std::nullopt;

	return true;
}

std::string BoolFactory::typeName() const
{
	return "bool";
}
