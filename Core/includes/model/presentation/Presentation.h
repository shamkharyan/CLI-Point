#pragma once

#include "Slide.h"

#include <list>
#include <string>
#include <memory>

class Presentation
{
public:
	Presentation(const std::string& name);

	void addSlide(std::unique_ptr<Slide> slide, std::size_t pos);
	void removeSlide(std::size_t pos);

	const std::string& getName() const;
	std::size_t slidesCount() const;
private:
	std::string m_name;
	std::list<std::unique_ptr<Slide>> m_slides;
};
