#include "cli/parsing/SizeTFactory.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

bool SizeTFactory::canParse(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return false;

	try
	{
		size_t idx = 0;
		std::ignore = std::stoull(argValue[0], &idx);
		return idx == argValue[0].size();
	}
	catch (...)
	{
		return false;
	}
}

ArgValue SizeTFactory::parse(const std::vector<std::string>& argValue) const
{
	if (!canParse(argValue))
		throw std::invalid_argument("Invalid integer value");

	size_t value = std::stoull(argValue[0]);
	return value;
}

std::string SizeTFactory::description() const
{
	return "Unsigned Integer value (e.g. 10, 0, 42)";
}
