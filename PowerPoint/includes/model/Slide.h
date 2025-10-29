#pragma once

#include "model/Shape.h"
#include "model/utils/Color.h"

#include <vector>
#include <memory>

namespace ppt::model
{
	class Slide
	{
	public:
		Slide(utils::Color bgColor) : m_bgColor(bgColor) {}
	private:
		std::vector<Shape> m_shapes;
		utils::Color m_bgColor;
	};
}
