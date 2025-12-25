#include "cli/parsing/parsers/ColorParser.h"
#include "utils/factories/ColorNameFactory.h"

#include <stdexcept>
#include <array>

using namespace ppt::utils::fact;
using namespace ppt::cli;

std::optional<ArgValue> ColorParser::tryCreate(const std::vector<std::string>& argValue) const
{
    if (argValue.size() == 1)
    {
        try
        {
            auto color = ColorNameFactory::create(argValue[0]);
            return ArgValue(color);
        }
        catch (const std::exception&)
        {
            return std::nullopt;
        }
    }

    if (argValue.size() == 3 || argValue.size() == 4)
    {
        try
        {
            std::array<std::uint8_t, 4> rgba = { 0, 0, 0, 255 };
            for (size_t i = 0; i < argValue.size(); ++i)
            {
                std::size_t pos = 0;
                unsigned long value = std::stoul(argValue[i], &pos);
                if (pos != argValue[i].size() || value > 255)
                    return std::nullopt;
                rgba[i] = static_cast<std::uint8_t>(value);
            }
            return ArgValue(model::utils::Color(rgba[0], rgba[1], rgba[2], rgba[3]));
        }
        catch (...)
        {
            return std::nullopt;
        }
    }

    return std::nullopt;
}


std::string ColorParser::typeName() const
{
	return "color";
}
