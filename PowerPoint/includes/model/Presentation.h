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

		std::size_t slidesCount() const;
		bool empty() const;

		void addSlide(const Slide& slide, std::size_t pos);
		void removeSlide(std::size_t pos);
		void replaceSlide(const Slide& slide, std::size_t pos);
		void moveSlide(std::size_t from, std::size_t to);
		void clearSlide(std::size_t pos);
		void setSlideColor(utils::Color color, std::size_t pos);

		void setName(const std::string& name);
		void setSelectedId(std::size_t pos);
		void markSaved();

		const Slide& getSlide(std::size_t pos) const;
		const std::string& getName() const;
		std::optional<std::size_t> getSelectedId() const;
		const std::vector<Slide>& getSlides() const;
		utils::Color getSlideColor(std::size_t pos) const;
		bool isModified() const;

	private:
		std::string m_name;
		std::vector<Slide> m_slides;
		std::optional<std::size_t> m_selected;
		bool m_modified = false;
	};
}
