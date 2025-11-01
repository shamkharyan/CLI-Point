#pragma once

#include "model/utils/ShapeType.h"
#include "model/utils/Color.h"
#include "model/utils/Coord.h"

#include <optional>
#include <string>

namespace ppt::core::act::utils
{
	struct AddShapeParams
	{
		std::optional<model::utils::ShapeType> type;
		std::optional<model::utils::Coord> position;
		std::optional<model::utils::Coord> size;
		std::optional<model::utils::Color> bgColor;
		std::optional<model::utils::Color> olColor;
		std::optional<std::size_t> olThickness;
		std::optional<std::size_t> at;
		std::optional<std::string> text;
	};
}