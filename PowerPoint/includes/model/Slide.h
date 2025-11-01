#pragma once

#include "model/Shape.h"
#include "model/utils/Color.h"

#include <vector>
#include <memory>

namespace ppt::model
{
	class Slide
	{
	public:
		Slide(utils::Color color);

		// Slide related methods
		void setColor(utils::Color ñolor);
		utils::Color getColor() const;

		// Shape related methods
		void appendShape(Shape shape);
		void appendShapeWithId(Shape shape);
		void removeShapeById(std::size_t id);
		void replaceShapeById(Shape shape, std::size_t id);
		void setShapePosition(std::size_t id, utils::Coord position);
		void setShapeType(std::size_t id, utils::ShapeType type);
		void setShapeSize(std::size_t id, utils::Coord size);
		void clear();
		bool empty() const;
		std::size_t shapesCount() const;
		const std::vector<Shape> getShapes() const;
		Shape getShapeById(std::size_t id) const;
		std::size_t getNextShapeId() const;
		bool isShapeExists(std::size_t id) const;
	private:
		std::vector<Shape>::const_iterator getShapeIterById(std::size_t id) const;
		std::vector<Shape>::iterator getShapeIterById(std::size_t id);
	private:
		std::vector<Shape> m_shapes;
		utils::Color m_color;

		std::size_t m_shapeId = 0;
	};
}
