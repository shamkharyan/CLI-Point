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
		std::uint8_t a;

		Color(std::uint8_t r = 0, std::uint8_t g = 0, std::uint8_t b = 0, std::uint8_t a = 255) : 
			r(r), g(g), b(b), a(a) {}
	};
}
