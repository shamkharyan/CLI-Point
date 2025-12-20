#include "visualization/renderers/SVGRenderer.h"
#include "model/utils/Color.h"

#include <iomanip>

using namespace ppt;
using namespace ppt::vis;

namespace
{
	std::string colorToSVG(const model::utils::Color& c)
	{
		std::ostringstream ss;
		float a = c.a / 255.0f;

		ss << std::fixed << std::setprecision(3);

		ss << "rgba("
			<< int(c.r) << ","
			<< int(c.g) << ","
			<< int(c.b) << ","
			<< a << ")";

		return ss.str();
	}
}

SVGRenderer::SVGRenderer(float width, float height) : m_width(width), m_height(height) {}

void SVGRenderer::beginDraw()
{
	m_ss << R"(<?xml version="1.0" encoding="UTF-8"?>)" << "\n";
	m_ss << "<svg "
		 << "xmlns=\"http://www.w3.org/2000/svg\" "
		 << "width=\"" << m_width << "\" "
		 << "height=\"" << m_height << "\" "
		 << "viewBox=\"0 0 " << m_width << " " << m_height << "\">\n";
}

void SVGRenderer::endDraw()
{
	m_ss << "</svg>\n";
}

void SVGRenderer::drawPath(const Path& path, const Pen& pen, const Brush& brush)
{
	m_ss << "  <path d=\"";

	for (const auto& cmd : path)
	{
		switch (cmd.type)
		{
		case PathCommand::Type::MoveTo:
			m_ss << "M " << cmd.p1.x << " " << cmd.p1.y << " ";
			break;
		case PathCommand::Type::LineTo:
			m_ss << "L " << cmd.p1.x << " " << cmd.p1.y << " ";
			break;
		case PathCommand::Type::QuadTo:
			m_ss << "Q "
				<< cmd.p1.x << " " << cmd.p1.y << ", "
				<< cmd.p2.x << " " << cmd.p2.y << " ";
			break;
		case PathCommand::Type::CubicTo:
			m_ss << "C "
				<< cmd.p1.x << " " << cmd.p1.y << ", "
				<< cmd.p2.x << " " << cmd.p2.y << ", "
				<< cmd.p3.x << " " << cmd.p3.y << " ";
			break;
		case PathCommand::Type::Close:
			m_ss << "Z ";
			break;
		}
	}

	m_ss << "\" ";

	// fill
	if (!brush.fillColor)
		m_ss << "fill=\"none\" ";
	else
		m_ss << "fill=\"" << colorToSVG(*brush.fillColor) << "\" ";

	// stroke
	if (pen.strokeWidth > 0)
	{
		m_ss << "stroke=\"" << colorToSVG(pen.color) << "\" ";
		m_ss << "stroke-width=\"" << pen.strokeWidth << "\" ";
	}
	else
		m_ss << "stroke=\"none\" ";

	m_ss << "/>\n";
}

void SVGRenderer::drawText(
	const std::string& text,
	float x,
	float y,
	const model::utils::TextStyle& style)
{
	m_ss << "  <text x=\"" << x << "\" y=\"" << y << "\" "
		<< "font-family=\"" << style.fontName << "\" "
		<< "font-size=\"" << style.fontSize << "\" "
		<< "fill=\"" << colorToSVG(style.fontColor) << "\">"
		<< text
		<< "</text>\n";
}

std::string SVGRenderer::str() const
{
	return m_ss.str();
}