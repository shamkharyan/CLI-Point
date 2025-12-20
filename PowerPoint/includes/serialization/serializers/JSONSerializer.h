#pragma once

#include "ISerializer.h"
#include "model/utils/Color.h"
#include "model/utils/Coord.h"
#include "model/SlideLayer.h"
#include "model/Slide.h"
#include "model/ShapeData.h"

#include "libs/json.hpp"

namespace ppt::ser
{
	class JSONSerializer : public ISerializer
	{
		using json = nlohmann::json;
	public:
		void serialize(const model::Presentation& presentation, const std::string& filePath) const override;
	private:
		void serializePresentation(json& jPresentation, const model::Presentation& presentation) const;
		void serializeSlide(json& jSlide, const model::Slide& slide) const;
		void serializeSlideLayer(json& jSlideLayer, const model::SlideLayer& slideLayer) const;
		void serializeShape(json& jShape, const model::ShapeData& shape) const;
		void serializeColor(json& jColor, const model::utils::Color& color) const;
	};
}