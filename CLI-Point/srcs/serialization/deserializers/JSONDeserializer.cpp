#include "serialization/deserializers/JSONDeserializer.h"

#include <fstream>

using namespace ppt::ser;

void JSONDeserializer::deserializeColor(const json& jColor, model::utils::Color& color) const
{
	color.r = jColor.at("r").get<uint8_t>();
	color.g = jColor.at("g").get<uint8_t>();
	color.b = jColor.at("b").get<uint8_t>();
	color.a = jColor.at("a").get<uint8_t>();
}

void JSONDeserializer::deserializeShape(const json& jShape, model::ShapeData& shape) const
{
	// Basic properties
	shape.id = jShape.at("id").get<std::size_t>();
	shape.type = jShape.at("type").get<std::string>();

	// Geometry
	shape.geometry.x = jShape.at("geometry").at("x").get<float>();
	shape.geometry.y = jShape.at("geometry").at("y").get<float>();
	shape.geometry.width = jShape.at("geometry").at("width").get<float>();
	shape.geometry.height = jShape.at("geometry").at("height").get<float>();

	// Basic style
	//shape.style.fillType = static_cast<model::utils::FillType>(jShape.at("style").at("fillType").get<int>());
	deserializeColor(jShape.at("style").at("outlineColor"), shape.style.outlineColor);
	shape.style.outlineWidth = jShape.at("style").at("outlineWidth").get<float>();
	deserializeColor(jShape.at("style").at("fillColor"), shape.style.fillColor);

	// Solid style
	//if (shape.style.fillType == model::utils::FillType::SolidColor)
	//	deserializeColor(jShape.at("style").at("fillColor"), shape.style.fillColor);
	//
	//// Gradient style
	//if (shape.style.fillType == model::utils::FillType::LinearGradient ||
	//	shape.style.fillType == model::utils::FillType::RadialGradient)
	//{
	//	shape.style.gradientStops.clear();
	//	for (const auto& jStop : jShape.at("style").at("gradientStops")) 
	//	{
	//		model::utils::StyleData::GradientStop stop;
	//		stop.position = jStop.at("position").get<float>();
	//		deserializeColor(jStop.at("color"), stop.color);
	//		shape.style.gradientStops.push_back(stop);
	//	}
	//	if (shape.style.fillType == model::utils::FillType::LinearGradient)
	//		shape.style.gradientAngle = jShape.at("style").at("gradientAngle").get<float>();
	//}
	//
	//// Image texture style
	//if (shape.style.fillType == model::utils::FillType::ImageTexture)
	//	shape.style.imagePath = jShape.at("style").at("imagePath").get<std::string>();

	if (jShape.contains("adjustments"))
	{
		const auto& jAdjustments = jShape.at("adjustments");
		if (jAdjustments.is_array())
		{
			shape.adjustments.clear();
			for (const auto& val : jAdjustments)
				shape.adjustments.push_back(val.get<float>());
		}
	}

	// Text data
	if (jShape.contains("text"))
	{
		shape.text = jShape.at("text");
		shape.textStyle.fontName = jShape.at("textStyle").at("fontName").get<std::string>();
		deserializeColor(jShape.at("textStyle").at("fontColor"), shape.textStyle.fontColor);
		shape.textStyle.fontSize = jShape.at("textStyle").at("fontSize").get<float>();
		
		/*shape.text->hAlign = static_cast<model::utils::TextData::HorizontalAlignment>(
			jText.at("hAlign").get<int>());
		shape.text->vAlign = static_cast<model::utils::TextData::VerticalAlignment>(
			jText.at("vAlign").get<int>());*/
	}
}

void JSONDeserializer::deserializeSlideLayer(const json& jSlideLayer, model::SlideLayer& slideLayer) const
{
	for (const auto& jShape : jSlideLayer.at("shapes"))
	{
		auto shape = std::make_shared<model::ShapeData>();
		deserializeShape(jShape, *shape);
		slideLayer.appendShape(shape);
	}
}

void JSONDeserializer::deserializeSlide(const json& jSlide, model::Slide& slide) const
{
	// Slide color
	model::utils::Color slideColor;
	deserializeColor(jSlide.at("color"), slideColor);
	slide.setColor(slideColor);

	// Layers
	for (const auto& jLayer : jSlide.at("layers"))
	{
		auto layer = std::make_shared<model::SlideLayer>();
		deserializeSlideLayer(jLayer, *layer);
		slide.appendLayer(layer);
	}
}

void JSONDeserializer::deserializePresentation(const json& jPresentation, model::Presentation& presentation) const
{
	// Presentation name
	presentation.setName(jPresentation.at("name").get<std::string>());

	// Slides
	for (const auto& jSlide : jPresentation.at("slides"))
	{
		auto slide = std::make_shared<model::Slide>();
		deserializeSlide(jSlide, *slide);
		presentation.appendSlide(slide);
	}
}

void JSONDeserializer::deserialize(model::Presentation& presentation, const std::string& filePath) const
{
	// Read JSON file
	std::ifstream inputFile(filePath);
	if (!inputFile.is_open())
		throw std::runtime_error("Could not open file: " + filePath);

	json jPresentation;
	inputFile >> jPresentation;

	// Deserialize presentation
	model::Presentation temp;
	deserializePresentation(jPresentation, temp);
	presentation = temp;
}