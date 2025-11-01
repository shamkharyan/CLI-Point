#pragma once

#include "Color.h"

namespace ppt::model::utils
{
	struct Style
	{
		Color backgroundColor;
		Color outlineColor;
		std::size_t outlineThickness;
	};
}