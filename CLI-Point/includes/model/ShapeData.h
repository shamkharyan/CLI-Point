#pragma once

#include "model/utils/GeometryData.h"
#include "model/utils/StyleData.h"
#include "model/utils/TextStyle.h"

#include <vector>

namespace ppt::model
{
	struct ShapeData
	{
		std::size_t id;
		std::string type;
		utils::GeometryData geometry;
		utils::StyleData style;
		std::string text;
		utils::TextStyle textStyle;

		std::vector<float> adjustments;
	};
}