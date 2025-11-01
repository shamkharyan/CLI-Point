#include "cli/utils/Converter.h"

#include <unordered_map>

using namespace ppt;
using namespace ppt::cli::utils;

std::optional<std::size_t> Converter::stringToSizeT(const std::string& str)
{
	std::size_t pos = 0;
	std::size_t val = 0;

	if (str[0] == '-')
		return std::nullopt;

	try
	{
		val = std::stoul(str, &pos);
	}
	catch (const std::exception&)
	{
		return std::nullopt;
	}

	if (pos != str.size())
		return std::nullopt;

	return val;
}

std::optional<model::utils::Color> Converter::stringToColor(const std::string& str)
{
	if (auto color = nameStringToColor(str))
		return color;

	if (auto color = hexStringToColor(str))
		return color;

	return std::nullopt;
}

std::optional<model::utils::Color> Converter::nameStringToColor(const std::string& str)
{
	using Color = model::utils::Color;

	static const std::unordered_map<std::string, Color> colorMap = {
				{"red",    Color(255, 0, 0)},
				{"green",  Color(0, 255, 0)},
				{"blue",   Color(0, 0, 255)},
				{"white",  Color(255, 255, 255)},
				{"black",  Color(0, 0, 0)},
				{"gray",   Color(128, 128, 128)},
				{"yellow", Color(255, 255, 0)},
				{"cyan",   Color(0, 255, 255)},
				{"magenta",Color(255, 0, 255)}
	};

	auto it = colorMap.find(str);
	if (it != colorMap.end())
		return it->second;

	return std::nullopt;
}

std::optional<model::utils::Color> Converter::hexStringToColor(const std::string& str)
{
	using Color = model::utils::Color;

	if (str.size() == 7 && str[0] == '#')
	{
		try
		{
			int r = std::stoi(str.substr(1, 2), nullptr, 16);
			int g = std::stoi(str.substr(3, 2), nullptr, 16);
			int b = std::stoi(str.substr(5, 2), nullptr, 16);
			return Color(r, g, b);
		}
		catch (...) { return std::nullopt; }
	}

	return std::nullopt;
}

std::optional<model::utils::Color> Converter::vectorToColor(const std::vector<std::string>& vec)
{
	if (vec.size() != 3)
		return std::nullopt;

	auto r = stringToSizeT(vec[0]);
	auto g = stringToSizeT(vec[1]);
	auto b = stringToSizeT(vec[2]);

	if (r && g && b &&
		r.value() <= 255 &&
		g.value() <= 255 &&
		b.value() <= 255)
		return model::utils::Color(r.value(), g.value(), b.value());
	return std::nullopt;
}

std::optional<model::utils::ShapeType> Converter::stringToShapeType(const std::string& str)
{
	if (str == "rectangle") return model::utils::ShapeType::Rectangle;
	if (str == "circle") return model::utils::ShapeType::Circle;
	if (str == "triangle") return model::utils::ShapeType::Triangle;

	return std::nullopt;
}