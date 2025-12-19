#pragma once

#include <variant>
#include <string>

#include <sstream>
#include <iomanip>

#include "model/utils/Color.h"
#include "model/utils/ShapeType.h"
#include "model/utils/Coord.h"

namespace ppt::cli
{
	using ArgValue = std::variant<
		std::string,
		std::size_t,
		float,
		bool,
		ppt::model::utils::Color,
		ppt::model::utils::ShapeType,
		ppt::model::utils::Coord
	>;
}