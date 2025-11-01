#pragma once

#include "model/Slide.h"
#include "model/Shape.h"
#include "model/Presentation.h"

namespace ppt::viewer::cli
{
	class CLIVisualizer
	{
	public:
		CLIVisualizer(std::ostream& os);
		void visualizePresentation(const model::Presentation& presentation);
		void visualizeSlide(const model::Slide& slide);
	private:
		void visualizeShape(const model::Shape& shape);
		//void visualizeBBox(const model::utils::BBox& bbox);
		void visualizeProperties(const model::utils::Properties& properties);
		void printColorln(const model::utils::Color color);
		void printCoordln(const model::utils::Coord coord);
	private:
		std::ostream& m_os;
	};
}
