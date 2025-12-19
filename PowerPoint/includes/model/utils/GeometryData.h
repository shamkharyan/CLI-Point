#pragma once

#include "Coord.h"

namespace ppt::model::utils
{
	struct GeometryData
	{
		Coord topLeft;
		Coord size;

		GeometryData(Coord topLeft = {0, 0}, Coord size = {0, 0})
			: topLeft(topLeft), size(size)
		{
		}
	};
}
