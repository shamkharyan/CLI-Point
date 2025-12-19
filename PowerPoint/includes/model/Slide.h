#pragma once

#include "model/SlideLayer.h"
#include "model/utils/Color.h"

#include <vector>
#include <cstddef>
#include <memory>

namespace ppt::model
{
	class Slide
	{
	public:
		using container = std::vector<std::shared_ptr<SlideLayer>>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

	public:

		Slide();
		explicit Slide(utils::Color color);

		std::size_t getNextId() noexcept { return m_nextId++; }

		void setColor(utils::Color color) noexcept;
		utils::Color getColor() const noexcept;

		std::size_t layersCount() const noexcept;
		bool empty() const noexcept;

		iterator begin() noexcept;
		iterator end() noexcept;

		const_iterator begin() const noexcept;
		const_iterator end() const noexcept;
		const_iterator cbegin() const noexcept;
		const_iterator cend() const noexcept;

		std::shared_ptr<SlideLayer> getLayer(std::size_t index) const;
		std::shared_ptr<SlideLayer> operator[](std::size_t index) const;

		void appendLayer(std::shared_ptr<SlideLayer> layer);
		void insertLayer(iterator pos, std::shared_ptr<SlideLayer> layer);
		std::shared_ptr<SlideLayer> removeLayer(iterator pos);

	private:
		void checkIndex(std::size_t index) const;

	private:
		std::size_t m_nextId = 1;

		container m_layers;
		utils::Color m_color;
	};
}
