#pragma once

#include "Coord.h"

class BBox
{
public:
	BBox() noexcept;
	BBox(Coord corner, Coord size) noexcept;

	Coord getCenter() const noexcept;
	Coord getMin() const noexcept;
	Coord getMax() const noexcept;
	Coord getSize() const noexcept;

	void setCorner(Coord corner) noexcept;
	void setSize(Coord size) noexcept;
private:
	Coord m_corner;
	Coord m_size;
};
