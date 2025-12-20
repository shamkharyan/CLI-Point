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

		std::string str() const;

	private:
		std::stringstream m_ss;
		float m_width;
		float m_height;
	};
}