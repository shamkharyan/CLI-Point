#pragma once

#include <variant>
#include <string>

#include "model/utils/Color.h"

namespace ppt::cli
{
	using ArgValue = std::variant<
		std::string,
		int,
		float,
		bool,
		ppt::model::utils::Color
	>;
}