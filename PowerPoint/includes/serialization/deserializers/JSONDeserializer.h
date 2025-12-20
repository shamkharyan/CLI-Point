#pragma once

#pragma once

#include "IDeserializer.h"
#include "model/utils/Color.h"
#include "model/utils/Coord.h"
#include "model/SlideLayer.h"
#include "model/Slide.h"
#include "model/ShapeData.h"

#include "libs/json.hpp"

namespace ppt::ser
{
	class JSONDeserializer : public IDeserializer
	{
		using json = nlohmann::json;
	public:
		void deserialize(model::Presentation& presentation, const std::string& filePath) const override;
	private:
		void deserializePresentation(const json& jPresentation, model::Presentation& presentation) const;
		void deserializeSlide(const json& jSlide, model::Slide& slide) const;
		void deserializeSlideLayer(const json& jSlideLayer, model::SlideLayer& slideLayer) const;
		void deserializeShape(const json& jShape, model::ShapeData& shape) const;
		void deserializeColor(const json& jColor, model::utils::Color& color) const;
	};
}