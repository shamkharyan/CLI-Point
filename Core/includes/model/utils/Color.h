#pragma once

#include <cstddef>

struct Color
{
	std::size_t r;
	std::size_t g;
	std::size_t b;

	Color(std::size_t r = 0, std::size_t g = 0, std::size_t b = 0) : r(r), g(g), b(b) {}
};
