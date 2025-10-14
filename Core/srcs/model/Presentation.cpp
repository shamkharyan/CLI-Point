#include "model/Presentation.h"
#include <stdexcept>

Presentation::Presentation(const std::string& name) : m_name(name) {}

const std::string& Presentation::getName() const
{
	return m_name;
}

void Presentation::addSlide(std::size_t pos)
{
	if (pos > slidesCount())
		throw std::runtime_error("Index out of bounds");
	m_slides.insert(std::next(m_slides.begin(), pos), Slide{});
}

void Presentation::removeSlide(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::runtime_error("Index out of bounds");
	m_slides.erase(std::next(m_slides.begin(), pos));
}

std::size_t Presentation::slidesCount() const
{
	return m_slides.size();
}