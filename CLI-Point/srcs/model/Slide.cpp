#include "model/Slide.h"

#include <stdexcept>
#include <utility>

namespace ppt::model
{
	Slide::Slide()
		: Slide(utils::Color(255, 255, 255))
	{
	}

	Slide::Slide(utils::Color color)
		: m_color(color)
	{
	}

	void Slide::setColor(utils::Color color) noexcept
	{
		m_color = color;
	}

	utils::Color Slide::getColor() const noexcept
	{
		return m_color;
	}

	std::size_t Slide::layersCount() const noexcept
	{
		return m_layers.size();
	}

	bool Slide::empty() const noexcept
	{
		return m_layers.empty();
	}

	Slide::iterator Slide::begin() noexcept
	{
		return m_layers.begin();
	}

	Slide::iterator Slide::end() noexcept
	{
		return m_layers.end();
	}

	Slide::const_iterator Slide::begin() const noexcept
	{
		return m_layers.cbegin();
	}

	Slide::const_iterator Slide::end() const noexcept
	{
		return m_layers.cend();
	}

	Slide::const_iterator Slide::cbegin() const noexcept
	{
		return m_layers.cbegin();
	}

	Slide::const_iterator Slide::cend() const noexcept
	{
		return m_layers.cend();
	}

	std::shared_ptr<SlideLayer> Slide::getLayer(std::size_t index) const
	{
		checkIndex(index);
		return m_layers[index];
	}


	std::shared_ptr<SlideLayer> Slide::operator[](std::size_t index) const
	{
		return getLayer(index);
	}

	void Slide::appendLayer(std::shared_ptr<SlideLayer> layer)
	{
		m_layers.push_back(std::move(layer));
	}

	void Slide::insertLayer(iterator pos, std::shared_ptr<SlideLayer> layer)
	{
		m_layers.insert(pos, std::move(layer));
	}

	std::shared_ptr<SlideLayer> Slide::removeLayer(iterator pos)
	{
		auto layer = *pos;
		m_layers.erase(pos);
		return layer;
	}

	void Slide::checkIndex(std::size_t index) const
	{
		if (index >= m_layers.size())
			throw std::out_of_range("Slide layer index out of range");
	}
}
	