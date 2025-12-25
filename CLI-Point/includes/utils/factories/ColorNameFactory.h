#pragma once

#include "model/utils/Color.h"

#include <unordered_map>

namespace ppt::utils::fact
{
	class ColorNameFactory
	{
		using ColorNameMap = std::unordered_map<std::string, ppt::model::utils::Color>;
	public:
		static ppt::model::utils::Color create(const std::string& rawValue);
		static const ColorNameMap getColorNameMap() { return m_colorNameMap; }
	private:
		static const ColorNameMap m_colorNameMap;
	};
}
