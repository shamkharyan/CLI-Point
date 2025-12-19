#pragma once

#include <vector>
#include <string>
#include <memory>

#include "model/ShapeData.h"

namespace ppt::model
{
	class SlideLayer
	{
	public:
		using container = std::vector<std::shared_ptr<ShapeData>>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

		std::size_t shapesCount() const noexcept;
		bool empty() const noexcept;

		iterator begin() noexcept;
		iterator end() noexcept;

		const_iterator begin() const noexcept;
		const_iterator end() const noexcept;
		const_iterator cbegin() const noexcept;
		const_iterator cend() const noexcept;

		std::shared_ptr<ShapeData> operator[](std::size_t pos) const;
		std::shared_ptr<ShapeData> getShape(std::size_t pos) const;

		void appendShape(std::shared_ptr<ShapeData> shape);
		void insertShape(iterator pos, std::shared_ptr<ShapeData> shape);
		void eraseShape(iterator pos);
		std::shared_ptr<ShapeData> removeShape(iterator pos);

		iterator findById(std::size_t id) noexcept;

	private:
		void checkIndex(std::size_t index) const;

	private:
		container m_shapes;
	};
}