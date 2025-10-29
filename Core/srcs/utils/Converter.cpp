#include "utils/Converter.h"

#include <unordered_map>

using namespace ppt;
using namespace ppt::utils;

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
	static const std::unordered_map<std::string, model::utils::Color> colorMap = {
		{"red",   {255, 0, 0}},
		{"green", {0, 255, 0}},
		{"blue",  {0, 0, 255}},
		{"white", {255, 255, 255}},
		{"black", {0, 0, 0}},
		{"yellow", {255, 255, 0}}
	};

	auto it = colorMap.find(str);
	if (it != colorMap.end())
		return it->second;

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