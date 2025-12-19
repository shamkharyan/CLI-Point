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

std::string CLIFormatter::toString(model::utils::ShapeType type)
{
	switch (type)
	{
	case model::utils::ShapeType::Rectangle:
		return "Rectangle";
	case model::utils::ShapeType::Circle:
		return "Circle";
	case model::utils::ShapeType::Triangle:
		return "Triangle";
	default:
		return "Unknown";
	}
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

std::string CLIFormatter::toColorNameString(model::utils::Color color)
{
	if (color.r == 255 && color.g == 0 && color.b == 0)
		return "Red";
	if (color.r == 0 && color.g == 255 && color.b == 0)
		return "Green";
	if (color.r == 0 && color.g == 0 && color.b == 255)
		return "Blue";
	if (color.r == 0 && color.g == 0 && color.b == 0)
		return "Black";
	if (color.r == 255 && color.g == 255 && color.b == 255)
		return "White";
	return "Unknown Color";
}

std::string CLIFormatter::toString(model::utils::Coord coord)
{
	return "(" + toString(coord.x) + ", " + toString(coord.y) + ")";
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
		std::string operator()(bool b) const
		{
			return toString(b);
		}
		std::string operator()(const ppt::model::utils::Color& color) const
		{
			return toHexColorString(color);
		}
		std::string operator()(ppt::model::utils::ShapeType type) const
		{
			return toString(type);
		}
		std::string operator()(ppt::model::utils::Coord coord) const
		{
			return toString(coord);
		}
		std::string operator()(std::monostate) const
		{
			return "null";
		}
	};
	return std::visit(ArgValueToStringVisitor{}, value);
}