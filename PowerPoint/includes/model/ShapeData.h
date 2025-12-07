#pragma once

#include "model/utils/GeometryData.h"
#include "model/utils/StyleData.h"
#include "model/utils/TextData.h"

#include <optional>

namespace ppt::model
{
	enum class ShapeType
	{
		Rectangle,
		Circle,
		Triangle
	};

	struct ShapeData
	{
		std::size_t id;
		ShapeType type;
		utils::GeometryData geometry;
		utils::StyleData style;
		std::optional<utils::TextData> text;
	};
}