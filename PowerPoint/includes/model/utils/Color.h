#pragma once

#include <cstdint>
#include <string>

namespace ppt::model::utils
{
	struct Color
	{
		std::uint8_t r;
		std::uint8_t g;
		std::uint8_t b;

		Color(std::uint8_t r = 0, std::uint8_t g = 0, std::uint8_t b = 0) : r(r), g(g), b(b) {}

		std::string toString() const
		{
			return "rgb(" + std::to_string((int)r) + "," + std::to_string((int)g) + "," + std::to_string((int)b) + ")";
		}
	};
}
