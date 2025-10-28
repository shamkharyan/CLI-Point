#pragma once

#include "model/shapes/AShape.h"
#include "model/utils/Color.h"

#include <list>
#include <memory>

namespace ppt::model
{
	class Slide
	{
	public:
		Slide(utils::Color bgColor) : m_bgColor(bgColor) {}
	private:
		std::list<std::unique_ptr<shapes::AShape>> m_shapes;
		utils::Color m_bgColor;
	};
}
