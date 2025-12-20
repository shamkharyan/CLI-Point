#pragma once

#include "model/utils/ShapeType.h"

#include <unordered_map>
#include <string>

namespace ppt::utils::fact
{
	class ShapeTypeFactory
	{
		using ShapeTypeMap = std::unordered_map<std::string, ppt::model::utils::ShapeType>;
	public:
		static ppt::model::utils::ShapeType create(const std::string& rawValue);
		static const ShapeTypeMap getShapeTypeMap() { return m_shapeTypeMap; }
	private:	
		static const std::unordered_map<std::string, ppt::model::utils::ShapeType> m_shapeTypeMap;
	};
}
