#pragma once


#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "AdjustmentMeta.h"
#include "visualization/factories/IShapeFactory.h"

namespace ppt::vis
{
	class ShapeMeta
	{
	public:
		using container = std::vector<AdjustmentMeta>;
		using alias_container = std::unordered_map<std::string, std::size_t>;
		using iterator = container::iterator;
		using const_iterator = container::const_iterator;

	public:
		ShapeMeta(const std::string& name, const std::shared_ptr<IShapeFactory>& factory);

		const std::string& getName() const noexcept { return m_name; }
		std::shared_ptr<IShapeFactory> getFactory() const noexcept { return m_factory; }
		std::size_t adjustmentCount() const noexcept { return m_adjMetas.size(); }
		
		const AdjustmentMeta* getAdjustmentMeta(const std::string& adjName) const;
		void registerAdjustmentMeta(AdjustmentMeta adjName);

		iterator begin() noexcept { return m_adjMetas.begin(); }
		iterator end() noexcept { return m_adjMetas.end(); }

		const_iterator begin() const noexcept { return m_adjMetas.begin(); }
		const_iterator end() const noexcept { return m_adjMetas.end(); }

		const_iterator cbegin() const noexcept { return m_adjMetas.cbegin(); }
		const_iterator cend() const noexcept { return m_adjMetas.cend(); }

	private:
		std::string m_name;
		std::shared_ptr<IShapeFactory> m_factory;
		container m_adjMetas;

		alias_container m_aliasIndexes;
	};
}
