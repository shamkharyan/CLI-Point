#pragma once

#include <optional>
#include <string>
#include <vector>

#include "model/utils/Color.h"

class Converter
{
public:
	static std::optional<std::size_t> stringToSizeT(const std::string& str);
	static std::optional<Color> stringToColor(const std::string& str);
	static std::optional<Color> vectorToColor(const std::vector<std::string>& vec);
private:
	Converter() = delete;
	Converter(const Converter&) = delete;
	Converter(Converter&&) noexcept = delete;
	Converter& operator=(const Converter&) = delete;
	Converter& operator=(Converter&&) noexcept = delete;
};
