#include "viewer/cli/CLIVisualizer.h"
#include "model/Slide.h"
#include "model/Shape.h"
#include "model/Presentation.h"

#include <ostream>

using namespace ppt::viewer::cli;

CLIVisualizer::CLIVisualizer(std::ostream& os) : m_os(os) {}

void CLIVisualizer::visualizePresentation(const model::Presentation& presentation)
{
	const auto& slides = presentation.getSlides();
	std::size_t id = 0;

	m_os << "Presentation \"" << presentation.getName() << "\"" << '\n';

	for (const auto& slide : slides)
	{
		m_os << "Slide #" << id++ << '\n';
		visualizeSlide(slide);
	}
}

void CLIVisualizer::visualizeSlide(const model::Slide& slide)
{
	const auto& shapes = slide.getShapes();
	const auto bgColor = slide.getBackgroundColor();

	m_os << "Background Color: ";
	printColorln(slide.getBackgroundColor());
	for (const auto& shape : shapes)
	{
		m_os << "Type: ";
		switch (shape.getType())
		{
		case model::Shape::Type::Circle:
			m_os << "Circle\n";
			break;
		case model::Shape::Type::Rect:
			m_os << "Rectangle\n";
			break;
		case model::Shape::Type::Triangle:
			m_os << "Triangle\n";
			break;
		default:
			m_os << "Unknown\n";
		}
		visualizeBBox(shape.getBBox());
		//visualizeProperties(shape.getProperties());
	}
}

void CLIVisualizer::visualizeBBox(const model::utils::BBox& bbox)
{
	m_os << "Geometry:\n";
	m_os << "Corner: ";
	printCoordln(bbox.getMin());
	m_os << "Width: " << bbox.getSize().x << '\n';
	m_os << "Height: " << bbox.getSize().y << '\n';
}

void CLIVisualizer::printColorln(const model::utils::Color color)
{
	m_os << "[r=" << (int)color.r << ", g=" << (int)color.g << ", b=" << (int)color.r << "]\n";
}

void CLIVisualizer::printCoordln(const model::utils::Coord coord)
{
	m_os << "[x=" << coord.x << ", y=" << coord.y << "]\n";
}

