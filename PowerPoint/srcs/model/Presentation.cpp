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
	return m_slides[pos];
}

Slide& Presentation::getSlide(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");
	return m_slides[pos];
}

void Presentation::addSlide(const Slide& slide, std::size_t pos)
{
	if (pos > slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides.insert(m_slides.begin() + pos, slide);

	if (m_slides.size() == 1)
		m_selected = 0;
	else if (m_selected && pos <= m_selected.value())
		++m_selected.value();
}

void Presentation::removeSlide(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides.erase(m_slides.begin() + pos);

	if (m_slides.empty())
		m_selected = std::nullopt;
	else if (m_selected && pos <= m_selected.value())
		m_selected = m_selected.value() > 0 ? m_selected.value() - 1 : 0;
}

void Presentation::nextSlide()
{
	if (m_selected && m_selected.value() < m_slides.size() - 1)
		++m_selected.value();
}

void Presentation::prevSlide()
{
	if (m_selected && m_selected.value() > 0)
		--m_selected.value();
}

bool Presentation::empty() const
{
	return m_slides.empty();
}

std::size_t Presentation::slidesCount() const
{
	return m_slides.size();
}

const std::vector<Slide>& Presentation::getSlides() const
{
	return m_slides;
}

std::optional<std::size_t> Presentation::getSelectedId() const
{
	return m_selected;
}

void Presentation::gotoSlide(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_selected = pos;
}