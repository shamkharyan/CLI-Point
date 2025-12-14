#include "model/Slide.h"

#include <stdexcept>
#include <utility>

namespace ppt::model
{
	// ================= ITERATOR =================

	Slide::iterator::iterator(Slide* slide, std::size_t layer, std::size_t index)
		: m_slide(slide), m_layer(layer), m_index(index)
	{
	}

	Slide::iterator::reference Slide::iterator::operator*() const
	{
		return m_slide->m_layers[m_layer][m_index];
	}

	Slide::iterator::pointer Slide::iterator::operator->() const
	{
		return &m_slide->m_layers[m_layer][m_index];
	}

	Slide::iterator& Slide::iterator::operator++()
	{
		advanceForward();
		return *this;
	}

	Slide::iterator Slide::iterator::operator++(int)
	{
		auto tmp = *this;
		++(*this);
		return tmp;
	}

	Slide::iterator& Slide::iterator::operator--()
	{
		advanceBackward();
		return *this;
	}

	Slide::iterator Slide::iterator::operator--(int)
	{
		auto tmp = *this;
		--(*this);
		return tmp;
	}

	bool Slide::iterator::operator==(const iterator& other) const
	{
		return m_slide == other.m_slide
			&& m_layer == other.m_layer
			&& m_index == other.m_index;
	}

	bool Slide::iterator::operator!=(const iterator& other) const
	{
		return !(*this == other);
	}

	void Slide::iterator::advanceForward()
	{
		if (!m_slide) return;

		++m_index;
		while (m_layer < m_slide->m_layers.size())
		{
			if (m_index < m_slide->m_layers[m_layer].size())
				return;

			++m_layer;
			m_index = 0;
		}

		// end()
		m_layer = m_slide->m_layers.size();
		m_index = 0;
	}

	void Slide::iterator::advanceBackward()
	{
		if (!m_slide) return;

		if (m_layer == m_slide->m_layers.size())
		{
			--m_layer;
			m_index = m_slide->m_layers[m_layer].size() - 1;
			return;
		}

		if (m_index > 0)
		{
			--m_index;
			return;
		}

		while (m_layer > 0)
		{
			--m_layer;
			if (!m_slide->m_layers[m_layer].empty())
			{
				m_index = m_slide->m_layers[m_layer].size() - 1;
				return;
			}
		}
	}

	// ================= SLIDE =================

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

	std::size_t Slide::shapesCount() const noexcept
	{
		return m_shapeCount;
	}

	bool Slide::empty() const noexcept
	{
		return m_shapeCount == 0;
	}

	Slide::iterator Slide::begin() noexcept
	{
		if (m_layers.empty())
			return end();

		return iterator(this, 0, 0);
	}

	Slide::iterator Slide::end() noexcept
	{
		return iterator(this, m_layers.size(), 0);
	}

	void Slide::appendShape(ShapeData shape)
	{
		shape.id = m_nextId++;

		if (m_layers.empty())
			m_layers.emplace_back();

		m_layers.back().push_back(std::move(shape));
		++m_shapeCount;
	}

	void Slide::appendShapeToLayer(std::size_t layer, ShapeData shape)
	{
		if (layer > m_layers.size())
			throw std::out_of_range("Layer index out of range");

		shape.id = m_nextId++;

		if (layer == m_layers.size())
			m_layers.emplace_back();

		m_layers[layer].push_back(std::move(shape));
		++m_shapeCount;
	}

	void Slide::eraseShape(iterator pos)
	{
		checkIterator(pos);

		auto& layer = m_layers[pos.m_layer];
		layer.erase(layer.begin() + pos.m_index);
		--m_shapeCount;

		if (layer.empty())
			m_layers.erase(m_layers.begin() + pos.m_layer);
	}

	void Slide::moveForward(iterator pos)
	{
		checkIterator(pos);

		auto& layer = m_layers[pos.m_layer];
		if (pos.m_index + 1 < layer.size())
			std::swap(layer[pos.m_index], layer[pos.m_index + 1]);
	}

	void Slide::moveBackward(iterator pos)
	{
		checkIterator(pos);

		auto& layer = m_layers[pos.m_layer];
		if (pos.m_index > 0)
			std::swap(layer[pos.m_index], layer[pos.m_index - 1]);
	}

	void Slide::moveToTop(iterator pos)
	{
		checkIterator(pos);

		ShapeData temp = std::move(*pos);
		eraseShape(pos);

		if (m_layers.empty())
			m_layers.emplace_back();

		m_layers.back().push_back(std::move(temp));
	}

	void Slide::moveToBottom(iterator pos)
	{
		checkIterator(pos);

		ShapeData temp = std::move(*pos);
		eraseShape(pos);

		if (m_layers.empty())
			m_layers.emplace_back();

		m_layers.front().insert(m_layers.front().begin(), std::move(temp));
	}

	Slide::iterator Slide::findById(std::size_t id) noexcept
	{
		for (std::size_t l = 0; l < m_layers.size(); ++l)
			for (std::size_t i = 0; i < m_layers[l].size(); ++i)
				if (m_layers[l][i].id == id)
					return iterator(this, l, i);

		return end();
	}

	void Slide::checkIterator(const iterator& it) const
	{
		if (it.m_slide != this || it.m_layer > m_layers.size())
			throw std::invalid_argument("Iterator does not belong to this slide");
	}
}
