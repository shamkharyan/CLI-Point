#include "cli/CLIFormatter.h"

using namespace ppt::cli;

std::string CLIFormatter::toString(bool value)
{
	return value ? "true" : "false";
}

std::string CLIFormatter::toString(std::size_t value)
{
	return std::to_string(value);
}

std::string CLIFormatter::toString(float value)
{
	return std::to_string(value);
}

std::string CLIFormatter::toString(const std::vector<float>& value)
{
	std::string txt = "(";
	for (float v : value)
		txt += std::to_string(v) + ", ";
	txt.back() = ')';
	return txt;
}

std::string CLIFormatter::toHexColorString(model::utils::Color color)
{
	char buffer[10];
	std::snprintf(buffer, sizeof(buffer), "#%02X%02X%02X%02X", color.r, color.g, color.b, color.a);
	return std::string(buffer);
}

std::string CLIFormatter::toRGBColorString(model::utils::Color color)
{
	char buffer[20];
	std::snprintf(buffer, sizeof(buffer), "rgba(%d, %d, %d, %d)", color.r, color.g, color.b, color.a);
	return std::string(buffer);
}

std::string CLIFormatter::toString(const ArgValue& value)
{
	struct ArgValueToStringVisitor
	{
		std::string operator()(const std::string& str) const
		{
			return str;
		}
		std::string operator()(std::size_t size) const
		{
			return toString(size);
		}
		std::string operator()(float f) const
		{
			return toString(f);
		}
		std::string operator()(const std::vector<float>& v)
		{
			return toString(v);
		}
		std::string operator()(bool b) const
		{
			return toString(b);
		}
		std::string operator()(const ppt::model::utils::Color& color) const
		{
			return toHexColorString(color);
		}
		std::string operator()(std::monostate) const
		{
			return "null";
		}
	};
	return std::visit(ArgValueToStringVisitor{}, value);
}