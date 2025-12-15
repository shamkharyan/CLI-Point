//#include "serialization/JSONSerializer.h"
//
//#include <fstream>
//
//using namespace ppt::serialization;
//
//void JSONSerializer::serializeColor(json& jColor, const model::utils::Color& color) const
//{
//	jColor = json::object();
//
//	jColor["r"] = color.r;
//	jColor["g"] = color.g;
//	jColor["b"] = color.b;
//	jColor["a"] = color.a;
//}
//
//void JSONSerializer::serializeShape(json& jShape, const model::ShapeData& shape) const
//{
//	jShape = json::object();
//
//	// Basic properties
//	jShape["id"] = shape.id;
//	jShape["type"] = static_cast<int>(shape.type);
//
//	// Geometry
//	jShape["geometry"] = json::object();
//	jShape["geometry"]["x"] = shape.geometry.x;
//	jShape["geometry"]["y"] = shape.geometry.y;
//	jShape["geometry"]["width"] = shape.geometry.width;
//	jShape["geometry"]["height"] = shape.geometry.height;
//
//	// Basic style
//	jShape["style"] = json::object();
//	jShape["style"]["fillType"] = static_cast<int>(shape.style.fillType);
//	serializeColor(jShape["style"]["outlineColor"], shape.style.outlineColor);
//	jShape["style"]["outlineWidth"] = shape.style.outlineWidth;
//
//	// Solid style
//	if (shape.style.fillType == model::utils::FillType::SolidColor)
//		serializeColor(jShape["style"]["fillColor"], shape.style.fillColor);
//
//	// Gradient style
//	if (shape.style.fillType == model::utils::FillType::LinearGradient ||
//		shape.style.fillType == model::utils::FillType::RadialGradient)
//	{
//		jShape["style"]["gradientStops"] = json::array();
//		for (const auto& stop : shape.style.gradientStops) {
//			json jStop = json::object();
//			jStop["position"] = stop.position;
//			serializeColor(jStop["color"], stop.color);
//			jShape["style"]["gradientStops"].push_back(jStop);
//		}
//		if (shape.style.fillType == model::utils::FillType::LinearGradient)
//			jShape["style"]["gradientAngle"] = shape.style.gradientAngle;
//	}
//
//	// Image texture style
//	if (shape.style.fillType == model::utils::FillType::ImageTexture)
//		jShape["style"]["imagePath"] = shape.style.imagePath;
//
//	// Text data
//	if (shape.text.has_value())
//	{
//		const auto& textData = shape.text.value();
//		jShape["text"] = json::object();
//		jShape["text"]["content"] = textData.content;
//		jShape["text"]["fontName"] = textData.fontName;
//		jShape["text"]["fontSize"] = textData.fontSize;
//		serializeColor(jShape["text"]["textColor"], textData.textColor);
//		jShape["text"]["hAlign"] = static_cast<int>(textData.hAlign);
//		jShape["text"]["vAlign"] = static_cast<int>(textData.vAlign);
//	}
//}
//
//void JSONSerializer::serializeSlide(json& jSlide, const model::Slide& slide) const
//{
//	jSlide = json::object();
//
//	serializeColor(jSlide["color"], slide.getColor());
//	jSlide["shapes"] = json::array();
//
//	for (auto it = slide.begin(); it != slide.end(); ++it)
//	{
//		const auto& shape = *it;
//		json jShape;
//		jShape["layer"] = slide.getLayer(it);
//		jShape["indexInLayer"] = slide.getIndexInLayer(it);
//		serializeShape(jShape, shape);
//		jSlide["shapes"].push_back(jShape);
//	}
//}
//
//void JSONSerializer::serializePresentation(json& jPresentation, const model::Presentation& presentation) const
//{
//	jPresentation = json::object();
//
//	jPresentation["name"] = presentation.getName();
//	jPresentation["slides"] = json::array();
//
//	for (const auto& slide : presentation)
//	{
//		json jSlide;
//		serializeSlide(jSlide, *slide);
//		jPresentation["slides"].push_back(jSlide);
//	}
//}
//
//void JSONSerializer::serialize(const model::Presentation& presentation, const std::string& filePath) const
//{
//	json jPresentation;
//	serializePresentation(jPresentation, presentation);
//
//	std::ofstream file(filePath);
//	if (!file.is_open())
//		throw std::runtime_error("Could not open file for writing: " + filePath);
//
//	file << jPresentation.dump(4); // Pretty print with 4 spaces indentation
//	file.close();
//}