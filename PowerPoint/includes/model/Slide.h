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

		const std::vector<Shape> getShapes() const { return m_shapes; }
		utils::Color getBackgroundColor() const { return m_bgColor; }

		void setBackgroundColor(utils::Color bgColor) { m_bgColor = bgColor; }
		void clear() { m_shapes.clear(); }
		bool empty() const { return m_shapes.empty(); }
	private:
		std::vector<Shape> m_shapes;
		utils::Color m_bgColor;
	};
}
