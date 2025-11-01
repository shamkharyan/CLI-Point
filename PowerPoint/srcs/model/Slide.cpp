#include "model/Slide.h"

#include <stdexcept>

using namespace ppt::model;

Slide::Slide(utils::Color color) : m_color(color) {}

const std::vector<Shape> Slide::getShapes() const { return m_shapes; }

utils::Color Slide::getColor() const { return m_color; }

void Slide::setColor(utils::Color bgColor) { m_color = bgColor; }

void Slide::clear() { m_shapes.clear(); }

bool Slide::empty() const { return m_shapes.empty(); }

void Slide::appendShapeWithId(Shape shape)
{
	if (isShapeExists(shape.id))
		throw std::runtime_error("Shape with given id exists");

	m_shapes.push_back(shape);
}

void Slide::appendShape(Shape shape)
{
	shape.id = m_shapeId++;
	m_shapes.push_back(shape); 
}

void Slide::removeShapeById(std::size_t id)
{
	auto it = getShapeIterById(id);
	m_shapes.erase(it);
}

void Slide::replaceShapeById(Shape shape, std::size_t id)
{
	auto it = getShapeIterById(id);
	shape.id = it->id;
	*it = shape;
}

Shape Slide::getShapeById(std::size_t id) const
{
	return *getShapeIterById(id);
}

std::vector<Shape>::iterator Slide::getShapeIterById(std::size_t id)
{
	auto it = std::find_if(m_shapes.begin(), m_shapes.end(),
		[id](const Shape& s) { return s.id == id; });

	if (it == m_shapes.end())
		throw std::runtime_error("Shape with given id not exists");

	return it;
}

std::vector<Shape>::const_iterator Slide::getShapeIterById(std::size_t id) const
{
	auto it = std::find_if(m_shapes.begin(), m_shapes.end(),
		[id](const Shape& s) { return s.id == id; });

	if (it == m_shapes.end())
		throw std::runtime_error("Shape with given id not exists");

	return it;
}

std::size_t Slide::getNextShapeId() const
{
	return m_shapeId;
}

std::size_t Slide::shapesCount() const
{
	return m_shapes.size();
}

bool Slide::isShapeExists(std::size_t id) const
{
	auto it = std::find_if(m_shapes.begin(), m_shapes.end(),
		[id](const Shape& s) { return s.id == id; });

	return it != m_shapes.end();
}

void Slide::setShapePosition(std::size_t id, utils::Coord position)
{
	auto it = getShapeIterById(id);
	it->geometry.position = position;
}

void Slide::setShapeType(std::size_t id, utils::ShapeType type)
{
	auto it = getShapeIterById(id);
	it->type = type;
}

void Slide::setShapeSize(std::size_t id, utils::Coord size)
{
	auto it = getShapeIterById(id);
	it->geometry.size = size;
}