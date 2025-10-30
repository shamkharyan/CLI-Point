#pragma once

#include "Color.h"

#include <string>
#include <optional>

namespace ppt::model::utils
{
	struct Properties
	{
		enum class FontStyle { Regular, Italic };
		enum class FontWeight { Normal, Bold };
		Color backgroundColor;
		Color outlineColor;
		std::size_t outlineThinkness;
		std::string text;
		Color textColor;
		std::string textFont;
		FontStyle fontStyle;
		FontWeight fontWeight;
	};
}