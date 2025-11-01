#include "model/Presentation.h"

#include <stdexcept>
#include <cassert>

using namespace ppt::model;

Presentation::Presentation(const std::string& name) : m_name(name) {}

const std::string& Presentation::getName() const { return m_name; }

void Presentation::setName(const std::string& name)
{
	m_name = name;
	m_modified = true;
}

const Slide& Presentation::getSlide(std::size_t pos) const
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");
	return m_slides[pos];
}

void Presentation::addSlide(const Slide& slide, std::size_t pos)
{
	if (pos > slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides.insert(m_slides.begin() + pos, slide);

	if (!m_selected.has_value())
		m_selected = 0;
	else if (pos <= m_selected.value())
		++m_selected.value();

	m_modified = true;
}

void Presentation::removeSlide(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides.erase(m_slides.begin() + pos);

	if (m_slides.empty()) 
		m_selected = std::nullopt;
	else if (m_selected.has_value()) 
	{
		if (pos < m_selected.value())
			--m_selected.value();
		else if (pos == m_selected.value())
			m_selected = std::min(pos, slidesCount() - 1);
	}

	m_modified = true;
}

void Presentation::moveSlide(std::size_t from, std::size_t to)
{
	if (from >= slidesCount() || to >= slidesCount())
		throw std::out_of_range("Slide index out of range");

	if (from == to)
		return;

	auto slide = std::move(m_slides[from]);
	m_slides.erase(m_slides.begin() + from);
	m_slides.insert(m_slides.begin() + to, std::move(slide));

	assert(m_selected.has_value());
	if (m_selected == from)
		m_selected = to;
	else if (from < m_selected && m_selected <= to)
		--m_selected.value();
	else if (to <= m_selected && m_selected < from)
		++m_selected.value();

	m_modified = true;
}


bool Presentation::empty() const
{
	return m_slides.empty();
}

std::size_t Presentation::slidesCount() const
{
	return m_slides.size();
}

std::optional<std::size_t> Presentation::getSelectedId() const
{
	return m_selected;
}

void Presentation::setSelectedId(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_selected = pos;
}

const std::vector<Slide>& Presentation::getSlides() const
{
	return m_slides;
}

void Presentation::replaceSlide(const Slide& slide, std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[pos] = slide;
	m_modified = true;
}

void Presentation::clearSlide(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	if (m_slides[pos].empty())
		return;

	m_slides[pos].clear();
	m_modified = true;
}

void Presentation::setSlideColor(utils::Color color, std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[pos].setColor(color);
	m_modified = true;
}

utils::Color Presentation::getSlideColor(std::size_t pos) const
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");
	
	return m_slides[pos].getColor();
}

bool Presentation::isModified() const { return m_modified; }

void Presentation::markSaved() { m_modified = false; }

void Presentation::addShape(const Shape& shape, std::size_t slidePos)
{
	if (slidePos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[slidePos].appendShape(shape);
	m_modified = true;
}

void Presentation::addShapeWithId(const Shape& shape, std::size_t slidePos)
{
	if (slidePos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[slidePos].appendShapeWithId(shape);
	m_modified = true;
}

void Presentation::removeShape(std::size_t shapeId, std::size_t slidePos)
{
	if (slidePos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[slidePos].removeShapeById(shapeId);
	m_modified = true;
}

void Presentation::replaceShape(const Shape& shape, std::size_t shapeId, std::size_t slidePos)
{
	if (slidePos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[slidePos].replaceShapeById(shape, shapeId);
	m_modified = true;
}

Shape Presentation::getShape(std::size_t shapeId, std::size_t slidePos) const
{
	if (slidePos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	return m_slides[slidePos].getShapeById(shapeId);
}

std::size_t Presentation::getNextShapeId(std::size_t slidePos) const
{
	if (slidePos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	return m_slides[slidePos].getNextShapeId();
}

void Presentation::setShapePosition(std::size_t shapeId, utils::Coord position, std::size_t slidePos)
{
	if (slidePos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[slidePos].setShapePosition(shapeId, position);
	m_modified = true;
}

void Presentation::setShapeSize(std::size_t shapeId, utils::Coord size, std::size_t slidePos)
{
	if (slidePos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[slidePos].setShapeSize(shapeId, size);
	m_modified = true;
}

bool Presentation::isShapeExists(std::size_t shapeId, std::size_t slidePos) const
{
	if (slidePos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	return m_slides[slidePos].isShapeExists(shapeId);
}

void Presentation::setShapeType(std::size_t shapeId, utils::ShapeType type, std::size_t slidePos)
{
	if (slidePos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[slidePos].setShapeType(shapeId, type);
	m_modified = true;
}