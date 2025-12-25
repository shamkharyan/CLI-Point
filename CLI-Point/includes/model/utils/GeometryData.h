#pragma once

namespace ppt::model::utils
{
	struct GeometryData
	{
		float x;
		float y;
		float width;
		float height;

		GeometryData(
			float x = 0,
			float y = 0,
			float width = 0,
			float height = 0) :
			x(x),
			y(y),
			width(width),
			height(height)
		{
		}
	};
}
