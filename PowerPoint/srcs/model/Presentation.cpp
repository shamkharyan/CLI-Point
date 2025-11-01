#include "model/Presentation.h"

#include <stdexcept>
#include <cassert>

using namespace ppt::model;

Presentation::Presentation(const std::string& name) : m_name(name) {}

const std::string& Presentation::getName() const { return m_name; }

void Presentation::setName(const std::string& name)
{
	m_name = name;
	m_modified = true;
}

const Slide& Presentation::getSlide(std::size_t pos) const
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

	if (!m_selected.has_value())
		m_selected = 0;
	else if (pos <= m_selected.value())
		++m_selected.value();

	m_modified = true;
}

void Presentation::removeSlide(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides.erase(m_slides.begin() + pos);

	if (m_slides.empty()) 
		m_selected = std::nullopt;
	else if (m_selected.has_value()) 
	{
		if (pos < m_selected.value())
			--m_selected.value();
		else if (pos == m_selected.value())
			m_selected = std::min(pos, slidesCount() - 1);
	}

	m_modified = true;
}

void Presentation::moveSlide(std::size_t from, std::size_t to)
{
	if (from >= slidesCount() || to >= slidesCount())
		throw std::out_of_range("Slide index out of range");

	if (from == to)
		return;

	auto slide = std::move(m_slides[from]);
	m_slides.erase(m_slides.begin() + from);
	m_slides.insert(m_slides.begin() + to, std::move(slide));

	assert(m_selected.has_value());
	if (m_selected == from)
		m_selected = to;
	else if (from < m_selected && m_selected <= to)
		--m_selected.value();
	else if (to <= m_selected && m_selected < from)
		++m_selected.value();

	m_modified = true;
}


bool Presentation::empty() const
{
	return m_slides.empty();
}

std::size_t Presentation::slidesCount() const
{
	return m_slides.size();
}

std::optional<std::size_t> Presentation::getSelectedId() const
{
	return m_selected;
}

void Presentation::setSelectedId(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_selected = pos;
}

const std::vector<Slide>& Presentation::getSlides() const
{
	return m_slides;
}

void Presentation::replaceSlide(const Slide& slide, std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[pos] = slide;
	m_modified = true;
}

void Presentation::clearSlide(std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	if (m_slides[pos].empty())
		return;

	m_slides[pos].clear();
	m_modified = true;
}

void Presentation::setSlideColor(utils::Color color, std::size_t pos)
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");

	m_slides[pos].setBackgroundColor(color);
	m_modified = true;
}

utils::Color Presentation::getSlideColor(std::size_t pos) const
{
	if (pos >= slidesCount())
		throw std::out_of_range("Index out of bounds");
	
	return m_slides[pos].getBackgroundColor();
}

bool Presentation::isModified() const { return m_modified; }

void Presentation::markSaved() { m_modified = false; }