#pragma once

#include <cstdint>
#include <string>

namespace ppt::model::utils
{
	struct Color
	{
		constexpr Color(std::uint8_t r = 0, std::uint8_t g = 0, std::uint8_t b = 0, std::uint8_t a = 255) : 
			r(r), g(g), b(b), a(a) {}

		std::uint8_t r;
		std::uint8_t g;
		std::uint8_t b;
		std::uint8_t a;
	};

	constexpr Color Red = Color(255, 0, 0);
	constexpr Color Green = Color(0, 255, 0);
	constexpr Color Blue = Color(0, 0, 255);
	constexpr Color White = Color(255, 255, 255);
	constexpr Color Black = Color(0, 0, 0);
	constexpr Color Cyan = Color(0, 255, 255);
	constexpr Color Magenta = Color(255, 0, 255);
	constexpr Color Yellow = Color(255, 255, 0);
}
