#pragma once

#include <variant>
#include <string>

#include "model/utils/Color.h"

#include "visualization/shapes/IShape.h"

namespace ppt::cli
{
	using ArgValue = std::variant<
		std::string,
		std::size_t,
		float,
		std::vector<float>,
		bool,
		ppt::model::utils::Color
	>;
}