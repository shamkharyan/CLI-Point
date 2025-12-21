#include "serialization/serializers/JSONSerializer.h"

#include <fstream>

using namespace ppt::ser;

void JSONSerializer::serializeColor(json& jColor, const model::utils::Color& color) const
{
	jColor = json::object();

	jColor["r"] = color.r;
	jColor["g"] = color.g;
	jColor["b"] = color.b;
	jColor["a"] = color.a;
}

void JSONSerializer::serializeShape(json& jShape, const model::ShapeData& shape) const
{
	jShape = json::object();

	// Basic properties
	jShape["id"] = shape.id;
	jShape["type"] = shape.type;

	// Geometry
	jShape["geometry"] = json::object();
	jShape["geometry"]["x"] = shape.geometry.topLeft.x;
	jShape["geometry"]["y"] = shape.geometry.topLeft.y;
	jShape["geometry"]["width"] = shape.geometry.size.x;
	jShape["geometry"]["height"] = shape.geometry.size.y;

	// Basic style
	jShape["style"] = json::object();
	//jShape["style"]["fillType"] = static_cast<int>(shape.style.fillType);
	serializeColor(jShape["style"]["outlineColor"], shape.style.outlineColor);
	jShape["style"]["outlineWidth"] = shape.style.outlineWidth;

	// Solid style
	/*if (shape.style.fillType == model::utils::FillType::SolidColor)
		serializeColor(jShape["style"]["fillColor"], shape.style.fillColor);*/

	// Gradient style
	//if (shape.style.fillType == model::utils::FillType::LinearGradient ||
	//	shape.style.fillType == model::utils::FillType::RadialGradient)
	//{
	//	jShape["style"]["gradientStops"] = json::array();
	//	for (const auto& stop : shape.style.gradientStops) {
	//		json jStop = json::object();
	//		jStop["position"] = stop.position;
	//		serializeColor(jStop["color"], stop.color);
	//		jShape["style"]["gradientStops"].push_back(jStop);
	//	}
	//	if (shape.style.fillType == model::utils::FillType::LinearGradient)
	//		jShape["style"]["gradientAngle"] = shape.style.gradientAngle;
	//}

	//// Image texture style
	//if (shape.style.fillType == model::utils::FillType::ImageTexture)
	//	jShape["style"]["imagePath"] = shape.style.imagePath;

	// Text data
	if (!shape.text.empty())
	{
		jShape["text"] = shape.text;
		jShape["textStyle"]["fontName"] = shape.textStyle.fontName;
		serializeColor(jShape["textStyle"]["fontColor"], shape.textStyle.fontColor);
		jShape["textStyle"]["fontSize"] = shape.textStyle.fontSize;
		/*jShape["textStyle"]["hAlign"] = static_cast<int>(textData.hAlign);
		jShape["textStyle"]["vAlign"] = static_cast<int>(textData.vAlign);*/
	}
}

void JSONSerializer::serializeSlideLayer(json& jSlideLayer, const model::SlideLayer& slideLayer) const
{
	jSlideLayer = json::object();
	jSlideLayer["shapes"] = json::array();

	for (const auto& shape : slideLayer)
	{
		json jShape;
		serializeShape(jShape, *shape);
		jSlideLayer["shapes"].push_back(jShape);
	}
}

void JSONSerializer::serializeSlide(json& jSlide, const model::Slide& slide) const
{
	jSlide = json::object();

	serializeColor(jSlide["color"], slide.getColor());
	jSlide["layers"] = json::array();

	for (const auto& layer : slide)
	{
		json jLayer;
		serializeSlideLayer(jLayer, *layer);
		jSlide["layers"].push_back(jLayer);
	}
}

void JSONSerializer::serializePresentation(json& jPresentation, const model::Presentation& presentation) const
{
	jPresentation = json::object();

	jPresentation["name"] = presentation.getName();
	jPresentation["slides"] = json::array();

	for (const auto& slide : presentation)
	{
		json jSlide;
		serializeSlide(jSlide, *slide);
		jPresentation["slides"].push_back(jSlide);
	}
}

void JSONSerializer::serialize(const model::Presentation& presentation, const std::string& filePath) const
{
	json jPresentation;
	serializePresentation(jPresentation, presentation);

	std::ofstream file(filePath);
	if (!file.is_open())
		throw std::runtime_error("Could not open file for writing: " + filePath);

	file << jPresentation.dump(2); // Pretty print with 2 spaces indentation
	file.close();
}