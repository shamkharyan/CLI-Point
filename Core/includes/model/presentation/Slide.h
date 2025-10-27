#pragma once

#include "model/presentation/objects/AShape.h"
#include "model/utils/Color.h"

#include <list>
#include <memory>

class Slide
{
public:
	Slide() = default;
	Slide(Color bgColor) : m_bgColor(bgColor) {}
private:
	std::list<std::unique_ptr<AShape>> m_shapes;
	Color m_bgColor;
};
