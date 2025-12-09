#pragma once

#include "serialization/ISerializer.h"

#include "libs/json.hpp"

namespace ppt::serialization
{
	class JSONSerializer : public ISerializer
	{
		using json = nlohmann::json;
	public:
		void serialize(const model::Presentation& presentation, const std::string& filePath) const override;
	private:
		void serializePresentation(json& jPresentation, const model::Presentation& presentation) const;
		void serializeSlide(json& jSlide, const model::Slide& slide) const;
		void serializeShape(json& jShape, const model::ShapeData& shape) const;
		void serializeColor(json& jColor, const model::utils::Color& color) const;
	};
}