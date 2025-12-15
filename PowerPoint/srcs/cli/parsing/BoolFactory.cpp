#include "cli/parsing/BoolFactory.h"

#include <stdexcept>

using namespace ppt::cli;

bool BoolFactory::canParse(const std::vector<std::string>& argValue) const
{
	return argValue.empty();
}

ArgValue BoolFactory::parse(const std::vector<std::string>& argValue) const
{
	if (!canParse(argValue))
		throw std::invalid_argument("Boolean flag does not accept values");

	return true;
}

std::string BoolFactory::description() const
{
	return "Boolean flag (true if present)";
}
