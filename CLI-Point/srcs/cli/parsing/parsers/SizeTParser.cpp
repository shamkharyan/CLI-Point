#include "cli/parsing/parsers/SizeTParser.h"

#include <stdexcept>
#include <string>

using namespace ppt::cli;

std::optional<ArgValue> SizeTParser::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 1)
		return std::nullopt;

    std::size_t pos = 0;
    unsigned long long value = 0;

    try
    {
        value = std::stoull(argValue[0], &pos, 10);
    }
    catch (...)
    {
        return std::nullopt;
    }

    if (pos != argValue[0].size())
        return std::nullopt;

    if (value > std::numeric_limits<std::size_t>::max())
        return std::nullopt;

    return static_cast<std::size_t>(value);
}

std::string SizeTParser::typeName() const
{
	return "size_t";
}
