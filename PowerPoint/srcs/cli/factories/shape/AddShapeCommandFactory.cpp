//#include "cli/factories/shape/AddShapeCommandFactory.h"
//#include "cli/commands/shape/AddShapeCommand.h"
//#include "model/ShapeData.h"
//#include "model/utils/GeometryData.h"
//#include "model/utils/StyleData.h"
//#include "model/utils/TextData.h"
//
//#include <stdexcept>
//#include <variant>
//
//using namespace ppt::cli;
//using namespace ppt::cli::factories;
//using namespace ppt::model;
//
//namespace
//{
//	ShapeType stringToShapeType(const std::string& str)
//	{
//		if (str == "rectangle" || str == "Rectangle")
//			return ShapeType::Rectangle;
//		if (str == "circle" || str == "Circle")
//			return ShapeType::Circle;
//		if (str == "triangle" || str == "Triangle")
//			return ShapeType::Triangle;
//		
//		throw std::invalid_argument("Invalid shape type: " + str);
//	}
//}
//
//AddShapeCommandFactory::AddShapeCommandFactory(core::ActionManager& actionManager, model::Presentation& presentation) :
//	m_actionManager(actionManager),
//	m_presentation(presentation)
//{
//}
//
//std::unique_ptr<cmds::ICommand> AddShapeCommandFactory::createCommand(const ParsedRawCommand& rcmd)
//{
//	// Required arguments
//	auto at = std::get<std::size_t>(rcmd.arguments.at("at"));
//	auto typeStr = std::get<std::string>(rcmd.arguments.at("type"));
//	auto x = static_cast<int>(std::get<float>(rcmd.arguments.at("x")));
//	auto y = static_cast<int>(std::get<float>(rcmd.arguments.at("y")));
//	auto width = static_cast<int>(std::get<float>(rcmd.arguments.at("width")));
//	auto height = static_cast<int>(std::get<float>(rcmd.arguments.at("height")));
//
//	ShapeType type = stringToShapeType(typeStr);
//	utils::GeometryData geometry(x, y, width, height);
//
//	// Optional arguments with defaults
//	utils::StyleData style;
//	if (rcmd.arguments.find("fill-color") != rcmd.arguments.end())
//		style.fillColor = std::get<utils::Color>(rcmd.arguments.at("fill-color"));
//	
//	if (rcmd.arguments.find("outline-color") != rcmd.arguments.end())
//		style.outlineColor = std::get<utils::Color>(rcmd.arguments.at("outline-color"));
//	
//	if (rcmd.arguments.find("outline-width") != rcmd.arguments.end())
//		style.outlineWidth = std::get<float>(rcmd.arguments.at("outline-width"));
//
//	std::optional<utils::TextData> text;
//	if (rcmd.arguments.find("text") != rcmd.arguments.end())
//	{
//		auto textStr = std::get<std::string>(rcmd.arguments.at("text"));
//		text = utils::TextData();
//		text->content = textStr;
//	}
//
//	std::size_t zIndex = 0;
//	if (rcmd.arguments.find("z-index") != rcmd.arguments.end())
//		zIndex = std::get<std::size_t>(rcmd.arguments.at("z-index"));
//
//	return std::make_unique<cmds::AddShapeCommand>(
//		m_presentation,
//		m_actionManager,
//		at,
//		type,
//		geometry,
//		style,
//		text,
//		zIndex
//	);
//}
