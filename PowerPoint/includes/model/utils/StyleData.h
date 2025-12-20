#pragma once

#include "Color.h"

#include <vector>
#include <optional>

namespace ppt::model::utils
{
	/*enum class FillType
	{
		SolidColor,
		LinearGradient,
		RadialGradient,
		ImageTexture
	};*/

	struct StyleData
	{
		//FillType fillType;

		Color outlineColor;
		float outlineWidth;

		// Only for SolidColor fill type
		std::optional<Color> fillColor;

		// Only for Gradient fill types
		//struct GradientStop
		//{
		//	float position; // 0.0 to 1.0
		//	Color color;
		//};
		//std::vector<GradientStop> gradientStops;
		//float gradientAngle = 0.0f; // Only for LinearGradient

		// Only for ImageTexture
		//std::string imagePath; 

		/*StyleData()
			: fillType(FillType::SolidColor), fillColor(255, 255, 255), outlineColor(0, 0, 0), outlineWidth(1.0f)
		{
		}*/
		StyleData()
			: outlineColor(0, 0, 0), outlineWidth(1.0f)
		{
		}

		StyleData(const Color& outlineColor, float outlineWidth, const std::optional<Color>& fillColor)
			: outlineColor(outlineColor), outlineWidth(outlineWidth), fillColor(fillColor)
		{
		}
	};
}