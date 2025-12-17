#include "cli/parsing/factories/SizeTFactory.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

bool SizeTFactory::canCreate(const std::vector<std::string>& argValue) const
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

ArgValue SizeTFactory::create(const std::vector<std::string>& argValue) const
{
	if (!canCreate(argValue))
		throw std::invalid_argument("Invalid size_t value");

	size_t value = std::stoull(argValue[0]);
	return value;
}

std::string SizeTFactory::typeName() const
{
	return "size_t";
}
