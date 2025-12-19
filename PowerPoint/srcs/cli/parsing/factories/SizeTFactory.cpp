#include "cli/parsing/factories/SizeTFactory.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

std::optional<ArgValue> SizeTFactory::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;
	try
	{
		size_t idx = 0;
		std::size_t value = std::stoull(argValue[0], &idx);
		if (idx != argValue[0].size())
			return std::nullopt;
		return value;
	}
	catch (...)
	{
		return std::nullopt;
	}
}

std::string SizeTFactory::typeName() const
{
	return "size_t";
}
