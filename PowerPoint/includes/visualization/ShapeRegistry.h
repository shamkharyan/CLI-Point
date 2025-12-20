#pragma once

#include "visualization/factories/IShapeFactory.h"

#include <unordered_map>
#include <string>
#include <memory>

namespace ppt::vis
{
	class ShapeRegistry
	{
	public:
		void registerFactory(const std::string& name, 
			std::shared_ptr<IShapeFactory> factory)
		{
			m_factoriesByName[name] = std::move(factory);
		}

		std::shared_ptr<IShapeFactory> getFactory(const std::string& name) const
		{
			auto it = m_factoriesByName.find(name);
			if (it == m_factoriesByName.end())
				return nullptr;
			return it->second;
		}

	private:
		std::unordered_map<std::string, std::shared_ptr<IShapeFactory>> m_factoriesByName;
	};
}
