#include "model/Presentation.h"
#include "model/Slide.h"

#include <stdexcept>

namespace ppt::model
{
	Presentation::Presentation()
		: Presentation("Untitled") {
	}

	Presentation::Presentation(const std::string& name)
		: m_name(name) 
	{
	}

	void Presentation::setName(const std::string& name) noexcept
	{
		m_name = name;
	}

	const std::string& Presentation::getName() const noexcept
	{
		return m_name;
	}

	std::size_t Presentation::slidesCount() const noexcept
	{
		return m_slides.size();
	}

	bool Presentation::empty() const noexcept
	{
		return m_slides.empty();
	}

	Presentation::iterator Presentation::begin() noexcept { return m_slides.begin(); }
	Presentation::iterator Presentation::end() noexcept { return m_slides.end(); }

	Presentation::const_iterator Presentation::begin() const noexcept { return m_slides.begin(); }
	Presentation::const_iterator Presentation::end() const noexcept { return m_slides.end(); }

	Presentation::const_iterator Presentation::cbegin() const noexcept { return m_slides.cbegin(); }
	Presentation::const_iterator Presentation::cend() const noexcept { return m_slides.cend(); }

	std::shared_ptr<Slide>& Presentation::operator[](std::size_t pos)
	{
		return m_slides[pos];
	}

	const std::shared_ptr<Slide>& Presentation::operator[](std::size_t pos) const
	{
		return m_slides[pos];
	}

	std::shared_ptr<Slide>& Presentation::getSlide(std::size_t pos)
	{
		checkIndex(pos);
		return m_slides[pos];
	}

	const std::shared_ptr<Slide>& Presentation::getSlide(std::size_t pos) const
	{
		checkIndex(pos);
		return m_slides[pos];
	}

	void Presentation::appendSlide(std::shared_ptr<Slide> slide)
	{
		m_slides.push_back(std::move(slide));
	}

	void Presentation::insertSlide(iterator pos, std::shared_ptr<Slide> slide)
	{
		m_slides.insert(pos, std::move(slide));
	}

	void Presentation::eraseSlide(iterator pos)
	{
		m_slides.erase(pos);
	}

	std::shared_ptr<Slide> Presentation::removeSlide(iterator pos)
	{
		auto slide = std::move(*pos);
		m_slides.erase(pos);
		return slide;
	}

	void Presentation::checkIndex(std::size_t index) const
	{
		if (index >= m_slides.size())
			throw std::out_of_range("Slide index out of range");
	}
}
