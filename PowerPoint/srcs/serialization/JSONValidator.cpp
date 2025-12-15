//#include "serialization/JSONValidator.h"
//
//using namespace ppt::serialization;
//
//bool JSONValidator::validateColor(const json& jColor) const
//{
//	if (!jColor.is_object())
//		return false;
//
//	constexpr std::array<const char*, 4> requiredKeys = { "r", "g", "b", "a" };
//
//	for (auto key : requiredKeys)
//	{
//		if (!jColor.contains(key))
//			return false;
//
//		const auto& value = jColor[key];
//
//		if (!value.is_number_integer())
//			return false;
//
//		int c = value.get<int>();
//		if (c < 0 || c > 255)
//			return false;
//	}
//
//	return true;
//}
//
//
//bool JSONValidator::validateShape(const json& jShape) const
//{
//	if (!jShape.is_object())
//		return false;
//
//	// Basic properties
//	if (!jShape.contains("id") || !jShape.at("id").is_number_unsigned())
//		return false;
//	if (!jShape.contains("type") || !jShape.at("type").is_number_integer())
//		return false;
//
//	// Geometry
//	if (!jShape.contains("geometry") || !jShape.at("geometry").is_object())
//		return false;
//	const auto& jGeometry = jShape.at("geometry");
//	if (!jGeometry.contains("x") || !jGeometry.at("x").is_number_integer())
//		return false;
//	if (!jGeometry.contains("y") || !jGeometry.at("y").is_number_integer())
//		return false;
//	if (!jGeometry.contains("width") || !jGeometry.at("width").is_number_integer())
//		return false;
//	if (!jGeometry.contains("height") || !jGeometry.at("height").is_number_integer())
//		return false;
//	// Basic style
//	if (!jShape.contains("style") || !jShape.at("style").is_object())
//		return false;
//	const auto& jStyle = jShape.at("style");
//	if (!jStyle.contains("fillType") || !jStyle.at("fillType").is_number_integer())
//		return false;
//	if (!jStyle.contains("outlineColor") || !validateColor(jStyle.at("outlineColor")))
//		return false;
//	if (!jStyle.contains("outlineWidth") || !jStyle.at("outlineWidth").is_number_float())
//		return false;
//	// Further validations can be added here for specific fill types
//	return true;
//}
//
//bool JSONValidator::validateSlide(const json& jSlide) const
//{
//	if (!jSlide.is_object())
//		return false;
//
//	// Color
//	if (!jSlide.contains("color") || !validateColor(jSlide.at("color")))
//		return false;
//
//	// Layers and shapes
//	if (!jSlide.contains("layers") || !jSlide.at("layers").is_array())
//		return false;
//
//	for (const auto& jLayer : jSlide.at("layers"))
//	{
//		if (!jLayer.is_array())
//			return false;
//
//		for (const auto& jShape : jLayer)
//		{
//			if (!validateShape(jShape))
//				return false;
//		}
//	}
//	return true;
//}
//
//bool JSONValidator::validatePresentation(const json& jPresentation) const
//{
//	if (!jPresentation.is_object())
//		return false;
//
//	// Validate "name"
//	auto itName = jPresentation.find("name");
//	if (itName == jPresentation.end() || !itName->is_string())
//		return false;
//
//	// Validate "slides"
//	auto itSlides = jPresentation.find("slides");
//	if (itSlides == jPresentation.end() || !itSlides->is_array())
//		return false;
//
//	for (const auto& jSlide : *itSlides)
//	{
//		if (!validateSlide(jSlide))
//			return false;
//	}
//
//	return true;
//}
