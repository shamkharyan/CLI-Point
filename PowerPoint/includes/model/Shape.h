#pragma once

#include "model/utils/BBox.h"

namespace ppt::model
{
	class Shape
	{
	public:
		enum class Type
		{
			Rect,
			Circle,
			Triangle
		};
	public:
		Type m_type;
		utils::BBox m_bbox;
	};
}