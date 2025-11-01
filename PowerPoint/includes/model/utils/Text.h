#pragma once

#include "Color.h"

#include <string>

namespace ppt::model::utils
{
	struct Text
	{
		std::string text;

		Text(const std::string& text) : text(text) {}
	};
}