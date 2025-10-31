#pragma once

#include "Slide.h"

#include <vector>
#include <string>
#include <optional>

namespace ppt::model
{
	class Presentation
	{
	public:
		Presentation(const std::string& name);

		const Slide& getSlide(std::size_t pos) const;
		Slide& getSlide(std::size_t pos);
		void addSlide(const Slide& slide, std::size_t pos);
		void removeSlide(std::size_t pos);
		void setName(const std::string& name);
		void nextSlide();
		void prevSlide();
		void gotoSlide(std::size_t pos);

		bool empty() const;
		const std::string& getName() const;
		std::size_t slidesCount() const;
		const std::vector<Slide>& getSlides() const;
		std::optional<std::size_t> getSelectedId() const;
	private:
		std::string m_name;
		std::vector<Slide> m_slides;
		std::optional<std::size_t> m_selected;
	};
}
