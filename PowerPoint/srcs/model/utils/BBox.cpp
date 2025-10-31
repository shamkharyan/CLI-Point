#include "model/utils/BBox.h"
#include "model/utils/Coord.h"

using namespace ppt::model::utils;

BBox::BBox(Coord corner, Coord size) noexcept :
	m_corner(corner),
	m_size(size)
{
}

Coord BBox::getCenter() const noexcept
{
	return { m_corner.x + m_size.x / 2, m_corner.y + m_size.y / 2 };
}

Coord BBox::getMin() const noexcept
{
	return m_corner;
}

Coord BBox::getMax() const noexcept
{
	return { m_corner.x + m_size.x, m_corner.y + m_size.y };
}
Coord BBox::getSize() const noexcept
{
	return m_size;
}

void BBox::setSize(Coord size) noexcept
{
	m_size = size;
}

void BBox::setCorner(Coord corner) noexcept
{
	m_corner = corner;
}