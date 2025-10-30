#pragma once

#include "model/utils/BBox.h"
#include "model/utils/Properties.h"

namespace ppt::model
{
	class Shape
	{
	public:
		enum class Type { Rect, Circle, Triangle };

		Type getType() const { return m_type; }
		utils::BBox getBBox() const { return m_bbox; }
		utils::Properties getProperties() const { return m_properties; }
	private:
		Type m_type;
		utils::BBox m_bbox;
		utils::Properties m_properties;
	};
}