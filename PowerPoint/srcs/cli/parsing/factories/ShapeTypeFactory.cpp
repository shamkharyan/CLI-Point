//#include "cli/parsing/factories/ShapeTypeFactory.h"
//#include "model/ShapeData.h"
//
//using namespace ppt::cli;
//
//bool ShapeTypeFactory::canCreate(const std::vector<std::string>& argValue) const
//{
//	return argValue.size() == 1;
//}
//
//ArgValue ShapeTypeFactory::create(const std::vector<std::string>& argValue) const
//{
//	const std::string& value = argValue[0];
//	if (value == "rectangle" || value == "Rectangle")
//		return ppt::model::utils::ShapeType::Rectangle;
//	if (value == "circle" || value == "Circle")
//		return ppt::model::utils::ShapeType::Circle;
//	if (value == "triangle" || value == "Triangle")
//		return ppt::model::utils::ShapeType::Triangle;
//	throw std::invalid_argument("Invalid shape type: " + value);
//}
//
