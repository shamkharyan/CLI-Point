#pragma once

#include "model/objects/Shape.h"

#include <list>
#include <memory>

class Slide
{
public:
	Slide() = default;
private:
	std::list<std::unique_ptr<Shape>> m_shapes;
};
