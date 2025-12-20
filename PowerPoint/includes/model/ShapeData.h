#pragma once

#include "model/utils/GeometryData.h"
#include "model/utils/StyleData.h"
#include "model/utils/TextData.h"

#include <optional>

namespace ppt::model
{
	struct ShapeData
	{
		std::size_t id;
		std::string type;
		utils::GeometryData geometry;
		utils::StyleData style;
		std::optional<utils::TextData> text;
	};
}