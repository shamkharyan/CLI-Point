#pragma once

#include "Color.h"

#include <vector>

namespace ppt::model::utils
{
	enum class FillType
	{
		SolidColor,
		LinearGradient,
		RadialGradient,
		ImageTexture
	};

	struct StyleData
	{
		FillType fillType;

		Color outlineColor;
		float outlineWidth;

		// Only for SolidColor fill type
		Color fillColor;

		// Only for Gradient fill types
		struct GradientStop
		{
			float position; // 0.0 to 1.0
			Color color;
		};
		std::vector<GradientStop> gradientStops;
		float gradientAngle = 0.0f; // Only for LinearGradient

		// Only for ImageTexture
		std::string imagePath; 

		StyleData()
			: fillType(FillType::SolidColor), fillColor(255, 255, 255), outlineColor(0, 0, 0), outlineWidth(1.0f)
		{
		}
	};
}