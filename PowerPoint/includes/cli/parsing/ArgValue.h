#pragma once

#include <variant>
#include <string>

#include "model/utils/Color.h"

namespace ppt::cli
{
	using ArgValue = std::variant<
		std::string,
		std::size_t,
		float,
		bool,
		ppt::model::utils::Color
	>;
}