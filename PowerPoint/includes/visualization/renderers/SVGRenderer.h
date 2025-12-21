#pragma once

#include "visualization/renderers/IRenderer.h"

#include <sstream>

namespace ppt::vis
{
	class SVGRenderer : public IRenderer
	{
	public:
		SVGRenderer(float width, float height);

		void beginDraw() override;
		void endDraw() override;

		void drawPath(const Path& path, const Pen& pen, const Brush& brush) override;

		void drawText(
			const std::string& text,
			const model::utils::GeometryData& geometry,
			const model::utils::TextStyle& style
		) override;

		void clear(const model::utils::Color& color) override;

		std::string str() const;

	private:
		std::stringstream m_ss;
		float m_width;
		float m_height;
	};
}