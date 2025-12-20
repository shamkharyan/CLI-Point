#include "serialization/exporters/SVGExporter.h"
#include "visualization/renderers/SVGRenderer.h"

#include <fstream>

using namespace ppt::ser;
using namespace ppt::vis;

SVGExporter::SVGExporter(const vis::ShapeRegistry& registry) : m_registry(registry) {}

void SVGExporter::exportSlide(const model::Slide& slide, const std::string& filePath) const
{
	std::ofstream file(filePath);
	if (!file.is_open())
		throw std::runtime_error("Could not open file for writing: " + filePath);

	SVGRenderer renderer(1920, 1080);
	renderer.beginDraw();

	for (const auto& layer : slide)
	{
		for (const auto& shapeData : *layer)
		{
			if (auto factory = m_registry.getFactory(shapeData->type))
			{
				auto shape = factory->create(*shapeData);
				shape->draw(renderer);
			}
		}
	}

	renderer.endDraw();

	file << renderer.str();
	file.close();
}