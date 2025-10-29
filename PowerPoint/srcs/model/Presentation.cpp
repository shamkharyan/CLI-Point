#include "model/Presentation.h"

#include <stdexcept>

using namespace ppt::model;

Presentation::Presentation(const std::string& name) : m_name(name) {}

const std::string& Presentation::getName() const { return m_name; }

void Presentation::setName(const std::string& name) { m_name = name; }

const Slide& Presentation::getSlide(std::size_t pos) const
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");
	auto it = m_slides.begin();
	std::advance(it, pos);
	return *it;
}

void Presentation::addSlide(const Slide& slide, std::size_t pos)
{
	if (pos > slidesCount())
		throw std::out_of_range("Index out of bounds");
	auto it = m_slides.begin();
	std::advance(it, pos);
	m_slides.insert(it, slide);
}

void Presentation::removeSlide(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");
	auto it = m_slides.begin();
	std::advance(it, pos);
	m_slides.erase(it);
}

std::size_t Presentation::slidesCount() const
{
	return m_slides.size();
}