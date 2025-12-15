//#include "serialization/JSONDeserializer.h"
//
//#include <fstream>
//
//using namespace ppt::serialization;
//
//void JSONDeserializer::deserializeColor(const json& jColor, model::utils::Color& color) const
//{
//	color.r = jColor.at("r").get<uint8_t>();
//	color.g = jColor.at("g").get<uint8_t>();
//	color.b = jColor.at("b").get<uint8_t>();
//	color.a = jColor.at("a").get<uint8_t>();
//}
//
//void JSONDeserializer::deserializeShape(const json& jShape, model::ShapeData& shape) const
//{
//	// Basic properties
//	shape.id = jShape.at("id").get<std::size_t>();
//	shape.type = static_cast<model::ShapeType>(jShape.at("type").get<int>());
//	
//	// Geometry
//	shape.geometry.x = jShape.at("geometry").at("x").get<int>();
//	shape.geometry.y = jShape.at("geometry").at("y").get<int>();
//	shape.geometry.width = jShape.at("geometry").at("width").get<int>();
//	shape.geometry.height = jShape.at("geometry").at("height").get<int>();
//	
//	// Basic style
//	shape.style.fillType = static_cast<model::utils::FillType>(jShape.at("style").at("fillType").get<int>());
//	deserializeColor(jShape.at("style").at("outlineColor"), shape.style.outlineColor);
//	shape.style.outlineWidth = jShape.at("style").at("outlineWidth").get<float>();
//	
//	// Solid style
//	if (shape.style.fillType == model::utils::FillType::SolidColor)
//		deserializeColor(jShape.at("style").at("fillColor"), shape.style.fillColor);
//	
//	// Gradient style
//	if (shape.style.fillType == model::utils::FillType::LinearGradient ||
//		shape.style.fillType == model::utils::FillType::RadialGradient)
//	{
//		shape.style.gradientStops.clear();
//		for (const auto& jStop : jShape.at("style").at("gradientStops")) 
//		{
//			model::utils::StyleData::GradientStop stop;
//			stop.position = jStop.at("position").get<float>();
//			deserializeColor(jStop.at("color"), stop.color);
//			shape.style.gradientStops.push_back(stop);
//		}
//		if (shape.style.fillType == model::utils::FillType::LinearGradient)
//			shape.style.gradientAngle = jShape.at("style").at("gradientAngle").get<float>();
//	}
//	
//	// Image texture style
//	if (shape.style.fillType == model::utils::FillType::ImageTexture)
//		shape.style.imagePath = jShape.at("style").at("imagePath").get<std::string>();
//
//	// Text data
//	if (jShape.contains("text"))
//	{
//		shape.text = model::utils::TextData();
//		const auto& jText = jShape.at("text");
//		shape.text->content = jText.at("content").get<std::string>();
//		shape.text->fontName = jText.at("fontName").get<std::string>();
//		shape.text->fontSize = jText.at("fontSize").get<float>();
//		deserializeColor(jText.at("textColor"), shape.text->textColor);
//		
//		shape.text->hAlign = static_cast<model::utils::TextData::HorizontalAlignment>(
//			jText.at("hAlign").get<int>());
//		shape.text->vAlign = static_cast<model::utils::TextData::VerticalAlignment>(
//			jText.at("vAlign").get<int>());
//	}
//}
//
//void JSONDeserializer::deserializeSlide(const json& jSlide, model::Slide& slide) const
//{
//	// Slide color
//	model::utils::Color slideColor;
//	deserializeColor(jSlide.at("color"), slideColor);
//	slide.setColor(slideColor);
//	
//	// Shapes
//	for (const auto& jShape : jSlide.at("shapes")) 
//	{
//		model::ShapeData shape;
//		deserializeShape(jShape, shape);
//		slide.appendShapeToLayer(jSlide.at("layer").get<std::size_t>(), shape);
//	}
//}
//
//void JSONDeserializer::deserializePresentation(const json& jPresentation, model::Presentation& presentation) const
//{
//	// Presentation name
//	presentation.setName(jPresentation.at("name").get<std::string>());
//	
//	// Slides
//	for (const auto& jSlide : jPresentation.at("slides")) 
//	{
//		model::Slide slide;
//		deserializeSlide(jSlide, slide);
//		presentation.appendSlide(slide);
//	}
//}
//
//void JSONDeserializer::deserialize(model::Presentation& presentation, const std::string& filePath) const
//{
//	// Read JSON file
//	std::ifstream inputFile(filePath);
//	if (!inputFile.is_open())
//		throw std::runtime_error("Could not open file: " + filePath);
//	
//	json jPresentation;
//	inputFile >> jPresentation;
//	
//	// Deserialize presentation
//	deserializePresentation(jPresentation, presentation);
//}