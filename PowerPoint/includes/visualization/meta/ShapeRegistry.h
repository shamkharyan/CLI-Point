#pragma once

#include "visualization/meta/ShapeMeta.h"

#include <vector>
#include <string>
#include <unordered_map>

namespace ppt::vis
{
	class ShapeRegistry
	{
	public:
		using container = std::vector<ShapeMeta>;
		using alias_container = std::unordered_map<std::string, std::size_t>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

	public:
		const ShapeMeta* getShapeMeta(const std::string& name) const noexcept;
		void registerShapeMeta(ShapeMeta shapeMeta);

		iterator begin() noexcept { return m_shapes.begin(); }
		iterator end() noexcept { return m_shapes.end(); }

		const_iterator begin() const noexcept { return m_shapes.begin(); }
		const_iterator end() const noexcept { return m_shapes.end(); }

		const_iterator cbegin() const noexcept { return m_shapes.cbegin(); }
		const_iterator cend() const noexcept { return m_shapes.cend(); }

	private:
		container m_shapes;

		alias_container m_aliasIndexes;
	};
}
