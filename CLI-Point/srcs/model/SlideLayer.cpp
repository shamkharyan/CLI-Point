#include "model/SlideLayer.h"

#include <stdexcept>

using namespace ppt::model;

std::size_t SlideLayer::shapesCount() const noexcept
{
	return m_shapes.size();
}

bool SlideLayer::empty() const noexcept
{
	return m_shapes.empty();
}

SlideLayer::iterator SlideLayer::begin() noexcept
{
	return m_shapes.begin();
}

SlideLayer::iterator SlideLayer::end() noexcept
{
	return m_shapes.end();
}

SlideLayer::const_iterator SlideLayer::begin() const noexcept
{
	return m_shapes.begin();
}

SlideLayer::const_iterator SlideLayer::end() const noexcept
{
	return m_shapes.end();
}

SlideLayer::const_iterator SlideLayer::cbegin() const noexcept
{
	return m_shapes.cbegin();
}

SlideLayer::const_iterator SlideLayer::cend() const noexcept
{
	return m_shapes.cend();
}

std::shared_ptr<ShapeData> SlideLayer::operator[](std::size_t pos) const
{
	return getShape(pos);
}

std::shared_ptr<ShapeData> SlideLayer::getShape(std::size_t pos) const
{
	checkIndex(pos);
	return m_shapes[pos];
}

void SlideLayer::appendShape(std::shared_ptr<ShapeData> shape)
{
	m_shapes.push_back(std::move(shape));
}

void SlideLayer::insertShape(iterator pos, std::shared_ptr<ShapeData> shape)
{
	m_shapes.insert(pos, std::move(shape));
}

void SlideLayer::eraseShape(iterator pos)
{
	m_shapes.erase(pos);
}

std::shared_ptr<ShapeData> SlideLayer::removeShape(iterator pos)
{
	auto shape = *pos;
	m_shapes.erase(pos);
	return shape;
}

SlideLayer::iterator SlideLayer::findById(std::size_t id) noexcept
{
	return std::find_if(m_shapes.begin(), m_shapes.end(),
		[id](const auto& shape) { return shape->id == id; });
}

void SlideLayer::checkIndex(std::size_t index) const
{
	if (index >= m_shapes.size())
		throw std::out_of_range("Shape index out of range");
}


