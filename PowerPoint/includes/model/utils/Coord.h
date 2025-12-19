#pragma once

#include <cstddef>

namespace ppt::model::utils
{
	struct Coord
	{
		std::size_t x;
		std::size_t y;

		Coord(std::size_t x = 0, std::size_t y = 0) : x(x), y(y) {}
	};
}
