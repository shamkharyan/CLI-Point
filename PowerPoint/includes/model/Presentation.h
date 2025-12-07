#pragma once

#include "Slide.h"

#include <vector>
#include <string>

namespace ppt::model
{
	class Presentation
	{
	public:
		using container = std::vector<Slide>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

		Presentation() : Presentation("Untitled") {}
		explicit Presentation(const std::string& name) : m_name(name) {}

		void setName(const std::string& name) noexcept { m_name = name; }
		const std::string& getName() const noexcept { return m_name; }

		std::size_t slidesCount() const noexcept { return m_slides.size(); }
		bool empty() const noexcept { return m_slides.empty(); }

		iterator begin() noexcept { return m_slides.begin(); }
		iterator end() noexcept { return m_slides.end(); }

		const_iterator begin() const noexcept { return m_slides.begin(); }
		const_iterator end() const noexcept { return m_slides.end(); }

		const_iterator cbegin() const noexcept { return m_slides.cbegin(); }
		const_iterator cend() const noexcept { return m_slides.cend(); }

		Slide& operator[](std::size_t pos) { return m_slides[pos]; }
		const Slide& operator[](std::size_t pos) const { return m_slides[pos]; }

		Slide& getSlide(std::size_t pos)
		{
			checkIndex(pos);
			return m_slides[pos];
		}

		const Slide& getSlide(std::size_t pos) const
		{
			checkIndex(pos);
			return m_slides[pos];
		}

		void appendSlide(const Slide& slide) { m_slides.push_back(slide); }
		void insertSlide(const_iterator pos, const Slide& slide) { m_slides.insert(pos, slide); }
		void eraseSlide(const_iterator pos) { m_slides.erase(pos); }
	private:
		void checkIndex(std::size_t index) const
		{
			if (index >= slidesCount())
				throw std::out_of_range("Slide index out of range");
		}
	private:
		std::string m_name;
		std::vector<Slide> m_slides;
	};
}
