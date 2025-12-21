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

	std::string escapeXML(const std::string& data) {
		std::string buffer;
		buffer.reserve(data.size());
		for (size_t pos = 0; pos != data.size(); ++pos) {
			switch (data[pos]) {
			case '&':  buffer.append("&amp;");       break;
			case '\"': buffer.append("&quot;");      break;
			case '\'': buffer.append("&apos;");      break;
			case '<':  buffer.append("&lt;");        break;
			case '>':  buffer.append("&gt;");        break;
			default:   buffer.append(1, data[pos]); break;
			}
		}
		return buffer;
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
	const model::utils::GeometryData& geometry,
	const model::utils::TextStyle& style)
{
	float x = geometry.x + (geometry.width / 2.0f);
	float y = geometry.y + (geometry.height / 2.0f);

	m_ss << "  <text "
		<< "x=\"" << x << "\" "
		<< "y=\"" << y << "\" "
		<< "font-family=\"" << style.fontName << "\" "
		<< "font-size=\"" << style.fontSize << "\" "
		<< "fill=\"" << colorToSVG(style.fontColor) << "\" "
		<< "text-anchor=\"middle\" "
		<< "dominant-baseline=\"central\">"
		<< escapeXML(text) 
		<< "</text>\n";
}

void SVGRenderer::clear(const model::utils::Color& color)
{
	m_ss << "  <rect "
		<< "width=\"" << m_width << "\" "
		<< "height=\"" << m_height << "\" "
		<< "fill=\"" << colorToSVG(color) << "\" "
		<< "stroke=\"none\" />\n";
}

std::string SVGRenderer::str() const
{
	return m_ss.str();
}