#include "cli/parsing/parsers/FloatParser.h"

#include <stdexcept>
#include <string>
#include <cmath>

using namespace ppt::cli;

std::optional<ArgValue> FloatParser::tryCreate(const std::vector<std::string>& argValue) const
{
    if (argValue.size() != 1)
        return std::nullopt;

    const std::string& s = argValue[0];
    std::size_t pos = 0;

    try
    {
        float value = std::stof(s, &pos);

        if (pos != s.size())
            return std::nullopt;

        if (!std::isfinite(value))
            return std::nullopt;

        return ArgValue(value);
    }
    catch (...)
    {
        return std::nullopt;
    }
}

std::string FloatParser::typeName() const
{
	return "float";
}
