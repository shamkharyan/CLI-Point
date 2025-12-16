#include "cli/parsing/factories/BoolFactory.h"

#include <stdexcept>

using namespace ppt::cli;

bool BoolFactory::canCreate(const std::vector<std::string>& argValue) const
{
	return argValue.empty();
}

ArgValue BoolFactory::create(const std::vector<std::string>& argValue) const
{
	if (!canCreate(argValue))
		throw std::invalid_argument("Boolean flag does not accept values");

	return true;
}

std::string BoolFactory::typeName() const
{
	return argValueTypeName(bool{});
}
