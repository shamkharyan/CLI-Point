#pragma once

#include "model/ShapeData.h"
#include "model/utils/Color.h"

#include <vector>
#include <cstddef>

namespace ppt::model
{
	class Slide
	{
	public:
		// ================= ITERATOR =================
		class iterator
		{
		public:
			using iterator_category = std::bidirectional_iterator_tag;
			using value_type = ShapeData;
			using difference_type = std::ptrdiff_t;
			using pointer = ShapeData*;
			using reference = ShapeData&;

			iterator() = default;

			reference operator*() const;
			pointer operator->() const;

			iterator& operator++();
			iterator operator++(int);

			iterator& operator--();
			iterator operator--(int);

			bool operator==(const iterator& other) const;
			bool operator!=(const iterator& other) const;

		private:
			friend class Slide;

			iterator(Slide* slide, std::size_t layer, std::size_t index);

			void advanceForward();
			void advanceBackward();

			Slide* m_slide = nullptr;
			std::size_t m_layer = 0;
			std::size_t m_index = 0;
		};

	public:
		// ================= SLIDE API =================
		Slide();
		explicit Slide(utils::Color color);

		void setColor(utils::Color color) noexcept;
		utils::Color getColor() const noexcept;

		std::size_t layersCount() const noexcept;
		std::size_t shapesCount() const noexcept;
		bool empty() const noexcept;

		iterator begin() noexcept;
		iterator end() noexcept;

		void appendShape(ShapeData shape);
		void appendShapeToLayer(std::size_t layer, ShapeData shape);

		void eraseShape(iterator pos);

		void moveForward(iterator pos);
		void moveBackward(iterator pos);
		void moveToTop(iterator pos);
		void moveToBottom(iterator pos);

		iterator findById(std::size_t id) noexcept;

	private:
		void checkIterator(const iterator& it) const;

	private:
		std::size_t m_nextId = 1;
		std::size_t m_shapeCount = 0;

		std::vector<std::vector<ShapeData>> m_layers;
		utils::Color m_color;
	};
}
