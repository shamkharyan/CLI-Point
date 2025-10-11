#pragma once

#include "Slide.h"

#include <list>
#include <string>

class Presentation
{
public:
	Presentation(const std::string& name);

	void addSlide(std::size_t pos);
	void removeSlide(std::size_t pos);
private:
	std::string m_name;
	std::list<Slide> m_slides;
};
