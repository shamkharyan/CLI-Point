#pragma once

#include <vector>
#include <string>
#include <memory>

namespace ppt::model
{
	class Slide;

	class Presentation
	{
	public:
		using container = std::vector<std::shared_ptr<Slide>>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

		Presentation();
		explicit Presentation(const std::string& name);

		void setName(const std::string& name) noexcept;
		const std::string& getName() const noexcept;

		std::size_t slidesCount() const noexcept;
		bool empty() const noexcept;

		iterator begin() noexcept;
		iterator end() noexcept;

		const_iterator begin() const noexcept;
		const_iterator end() const noexcept;
		const_iterator cbegin() const noexcept;
		const_iterator cend() const noexcept;

		std::shared_ptr<Slide> operator[](std::size_t pos) const;
		std::shared_ptr<Slide> getSlide(std::size_t pos) const;

		void appendSlide(std::shared_ptr<Slide> slide);
		void insertSlide(iterator pos, std::shared_ptr<Slide> slide);
		void eraseSlide(iterator pos);
		std::shared_ptr<Slide> removeSlide(iterator pos);

	private:
		void checkIndex(std::size_t index) const;

	private:
		std::string m_name;
		container m_slides;
	};
}
