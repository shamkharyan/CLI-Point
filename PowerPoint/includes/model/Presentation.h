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

		// Presentation related methods
		void setName(const std::string& name);
		void setSelectedId(std::size_t pos);
		void markSaved();
		const std::string& getName() const;
		std::optional<std::size_t> getSelectedId() const;
		bool isModified() const;

		// Slides related methods
		void addSlide(const Slide& slide, std::size_t pos);
		void removeSlide(std::size_t pos);
		void replaceSlide(const Slide& slide, std::size_t pos);
		void moveSlide(std::size_t from, std::size_t to);
		void clearSlide(std::size_t pos);
		void setSlideColor(utils::Color color, std::size_t pos);
		std::size_t slidesCount() const;
		bool empty() const;
		const Slide& getSlide(std::size_t pos) const;
		const std::vector<Slide>& getSlides() const;
		utils::Color getSlideColor(std::size_t pos) const;
		
		// Shape related methods
		void addShape(const Shape& shape, std::size_t slidePos);
		void addShapeWithId(const Shape& shape, std::size_t slidePos);
		void removeShape(std::size_t shapeId, std::size_t slidePos);
		void replaceShape(const Shape& shape, std::size_t shapeId, std::size_t slidePos);
		void setShapePosition(std::size_t shapeId, utils::Coord position, std::size_t slidePos);
		void setShapeSize(std::size_t shapeId, utils::Coord size, std::size_t slidePos);
		void setShapeType(std::size_t shapeId, utils::ShapeType type, std::size_t slidePos);
		Shape getShape(std::size_t shapeId, std::size_t pos) const;
		std::size_t getNextShapeId(std::size_t slidePos) const;
		bool isShapeExists(std::size_t shapeId, std::size_t slidePos) const;
	private:
		std::string m_name;
		std::vector<Slide> m_slides;
		std::optional<std::size_t> m_selected;
		bool m_modified = false;
	};
}
