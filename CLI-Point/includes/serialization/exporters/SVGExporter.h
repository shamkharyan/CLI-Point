#pragma once

#include "IExporter.h"
#include "visualization/meta/ShapeRegistry.h"

namespace ppt::ser
{
	class SVGExporter : public IExporter
	{
	public:
		SVGExporter(const vis::ShapeRegistry& registry);

		void exportSlide(const model::Slide& slide, const std::string& filePath) const override;
	private:
		const vis::ShapeRegistry& m_registry;
	};
}