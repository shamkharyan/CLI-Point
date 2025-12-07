#pragma once

#include "model/ShapeData.h"
#include "model/utils/Color.h"

#include <vector>
#include <stdexcept>

namespace ppt::model
{
	class Slide
	{
	private:
		template <typename T, typename Ptr, typename Ref>
		class base_iterator
		{
			friend class Slide;
		public:
			using value_type = T;
			using pointer = Ptr;
			using reference = Ref;
			using difference_type = std::ptrdiff_t;
			using iterator_category = std::bidirectional_iterator_tag;

		protected:
			const Slide* m_slide;
			std::size_t m_layer;
			std::size_t m_index;

		public:
			base_iterator(const Slide* slide, std::size_t layer, std::size_t index)
				: m_slide(slide), m_layer(layer), m_index(index)
			{
			}

			operator base_iterator<const T, const T*, const T&>() const
			{
				return base_iterator<const T, const T*, const T&>(m_slide, m_layer, m_index);
			}

			Ref operator*() const { return const_cast<Slide*>(m_slide)->m_layers[m_layer][m_index]; }
			Ptr operator->() const { return &const_cast<Slide*>(m_slide)->m_layers[m_layer][m_index]; }

			base_iterator& operator++() { advanceForward(); return *this; }
			base_iterator& operator--() { advanceBackward(); return *this; }

			base_iterator operator++(int) { base_iterator tmp = *this; ++(*this); return tmp; }
			base_iterator operator--(int) { base_iterator tmp = *this; --(*this); return tmp; }

			bool operator==(const base_iterator& other) const
			{
				return m_slide == other.m_slide && m_layer == other.m_layer && m_index == other.m_index;
			}

			bool operator!=(const base_iterator& other) const
			{
				return !(*this == other);
			}

		private:
			void advanceForward()
			{
				if (!m_slide) return;
				++m_index;

				while (m_layer < m_slide->m_layers.size() &&
					m_index >= m_slide->m_layers[m_layer].size())
				{
					++m_layer;
					m_index = 0;
				}

				if (m_layer >= m_slide->m_layers.size())
				{
					m_slide = nullptr;
					m_layer = m_index = 0;
				}
			}

			void advanceBackward()
			{
				if (!m_slide) return;

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

				m_slide = nullptr;
				m_layer = m_index = 0;
			}
		};

	public:
		using iterator = base_iterator<ShapeData, ShapeData*, ShapeData&>;
		using const_iterator = base_iterator<const ShapeData, const ShapeData*, const ShapeData&>;

		Slide() : Slide(utils::Color(255, 255, 255)) {}
		explicit Slide(utils::Color color) : m_color(color) {}

		void setColor(utils::Color color) noexcept { m_color = color; }
		utils::Color getColor() const noexcept { return m_color; }

		std::size_t layersCount() const noexcept { return m_layers.size(); }
		bool empty() const noexcept { return m_layers.empty(); }
		std::size_t shapesCount() const
		{
			std::size_t count = 0;
			for (const auto& layer : m_layers)
				count += layer.size();
			return count;
		}

		std::size_t shapesCountInLayer(std::size_t layer) const
		{
			if (layer >= m_layers.size())
				throw std::out_of_range("Layer index out of range");
			return m_layers[layer].size();
		}

		iterator begin() { return iterator(this, 0, 0); }
		iterator end() { return iterator(nullptr, 0, 0); }
		const_iterator begin() const { return const_iterator(this, 0, 0); }
		const_iterator end() const { return const_iterator(nullptr, 0, 0); }
		const_iterator cbegin() const { return begin(); }
		const_iterator cend() const { return end(); }


		std::size_t getLayer(const_iterator it) const
		{
			checkBelongsToThisSlide(it);
			return it.m_layer;
		}

		std::size_t getIndexInLayer(const_iterator it) const
		{
			checkBelongsToThisSlide(it);
			return it.m_index;
		}

		void appendShape(ShapeData shape)
		{
			shape.id = m_nextShapeId++;

			if (m_layers.empty())
				m_layers.emplace_back();
			m_layers.back().push_back(std::move(shape));
		}

		void appendShapeToLayer(std::size_t layer, ShapeData shape)
		{
			shape.id = m_nextShapeId++;

			if (layer > m_layers.size())
				throw std::out_of_range("Layer index out of range");
			if (layer == m_layers.size())
				m_layers.emplace_back();
			m_layers[layer].push_back(std::move(shape));
		}

		void insertShape(iterator pos, ShapeData shape)
		{
			checkBelongsToThisSlide(pos);
			shape.id = m_nextShapeId++;

			if (pos.m_layer >= m_layers.size())
				throw std::out_of_range("Invalid iterator position");

			m_layers[pos.m_layer].insert(m_layers[pos.m_layer].begin() + pos.m_index, std::move(shape));
		}

		void eraseShape(iterator pos)
		{
			checkBelongsToThisSlide(pos);

			auto& layer = m_layers[pos.m_layer];
			layer.erase(layer.begin() + pos.m_index);

			if (layer.empty())
				m_layers.erase(m_layers.begin() + pos.m_layer);
		}

		void moveShapeForward(iterator pos)
		{
			checkBelongsToThisSlide(pos);

			auto& layer = m_layers[pos.m_layer];

			if (pos.m_index + 1 >= layer.size())
				return;

			std::swap(layer[pos.m_index], layer[pos.m_index + 1]);
		}

		void moveShapeBackward(iterator pos)
		{
			checkBelongsToThisSlide(pos);

			auto& layer = m_layers[pos.m_layer];

			if (pos.m_index == 0)
				return;

			std::swap(layer[pos.m_index], layer[pos.m_index - 1]);
		}

		void moveToTop(iterator pos)
		{
			checkBelongsToThisSlide(pos);

			if (m_layers.empty())
				return;

			ShapeData temp = *pos;
			eraseShape(pos);

			m_layers.back().push_back(std::move(temp));
		}

		void moveToBottom(iterator pos)
		{
			checkBelongsToThisSlide(pos);

			ShapeData temp = *pos;
			eraseShape(pos);

			if (m_layers.empty())
				m_layers.emplace_back();

			m_layers.front().insert(m_layers.front().begin(), std::move(temp));
		}

		iterator findShapeById(std::size_t id)
		{
			for (std::size_t l = 0; l < m_layers.size(); ++l)
				for (std::size_t i = 0; i < m_layers[l].size(); ++i)
					if (m_layers[l][i].id == id)
						return iterator(this, l, i);

			return end();
		}

		const_iterator findShapeById(std::size_t id) const
		{
			for (std::size_t l = 0; l < m_layers.size(); ++l)
				for (std::size_t i = 0; i < m_layers[l].size(); ++i)
					if (m_layers[l][i].id == id)
						return const_iterator(this, l, i);

			return cend();
		}

	private:
		template <typename Iter>
		void checkBelongsToThisSlide(Iter it) const
		{
			if (it.m_slide != this)
				throw std::invalid_argument("Iterator does not belong to this slide");
		}

	private:
		std::size_t m_nextShapeId = 1;
		std::vector<std::vector<ShapeData>> m_layers;
		utils::Color m_color;
	};
}