#pragma once

#include "Slide.h"

#include <list>
#include <memory>
#include <string>

namespace ppt::model
{
	class Presentation
	{
	public:
		Presentation(const std::string& name);

		const Slide& getSlide(std::size_t pos) const;
		void addSlide(const Slide& slide, std::size_t pos);
		void removeSlide(std::size_t pos);
		void setName(const std::string& name);

		const std::string& getName() const;
		std::size_t slidesCount() const;
	private:
		std::string m_name;
		std::list<Slide> m_slides;
	};
}
