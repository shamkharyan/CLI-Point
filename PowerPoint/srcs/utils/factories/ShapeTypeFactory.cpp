#include "utils/factories/ShapeTypeFactory.h"

#include <stdexcept>

using namespace ppt::utils::fact;

const std::unordered_map<std::string, ppt::model::utils::ShapeType> ShapeTypeFactory::m_shapeTypeMap =
{
	{"rectangle", ppt::model::utils::ShapeType::Rectangle},
	{"ellipse", ppt::model::utils::ShapeType::Ellipse},
	{"triangle", ppt::model::utils::ShapeType::Triangle}
};

ppt::model::utils::ShapeType ShapeTypeFactory::create(const std::string& rawValue)
{
	auto it = m_shapeTypeMap.find(rawValue);
	if (it != m_shapeTypeMap.end())
		return it->second;

	throw std::invalid_argument("Invalid shape type: " + rawValue);
}