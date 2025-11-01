#pragma once

#include "model/utils/Geometry.h"
#include "model/utils/Properties.h"
#include "model/utils/ShapeType.h"

namespace ppt::model
{
	class Shape
	{
	private:
		utils::ShapeType m_type;
		utils::Geometry m_geometry;
	};
}