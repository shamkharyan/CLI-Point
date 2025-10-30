#include "model/utils/BBox.h"
#include "model/utils/Coord.h"

using namespace ppt::model::utils;

BBox::BBox(Coord corner, Coord size) noexcept :
	m_corner(corner),
	m_size(size)
{
}

BBox::BBox() noexcept : BBox({ 0.f,0.f }, { 0.f, 0.f }) {}

Coord BBox::getCenter() const noexcept
{
	return { m_corner.x + m_size.x / 2.f, m_corner.y + m_size.y / 2.f };
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