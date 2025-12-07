#pragma once

namespace ppt::model::utils
{
	struct GeometryData
	{
		int x;
		int y;
		int width;
		int height;

		GeometryData(int x = 0, int y = 0, int width = 0, int height = 0)
			: x(x), y(y), width(width), height(height) 
		{
		}
	};
}
