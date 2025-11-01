#pragma once

#include "model/utils/Geometry.h"
#include "model/utils/Style.h"
#include "model/utils/ShapeType.h"
#include "model/utils/Text.h"

#include <optional>

namespace ppt::model
{
	struct Shape
	{
		std::size_t id;
		utils::ShapeType type;
		utils::Geometry geometry;
		utils::Style style;
		std::optional<utils::Text> text;
	};
}