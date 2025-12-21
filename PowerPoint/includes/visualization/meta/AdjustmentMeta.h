#pragma once

#include <string>
#include <vector>
#include <memory>
#include <optional>

namespace ppt::vis
{
	class AdjustmentMeta
	{
	public:
		AdjustmentMeta(
			const std::string& name, 
			const std::string& description, 
			float defaultValue,
			float minValue,
			float maxValue) : 
			m_name(name),
			m_description(description), 
			m_defaultValue(defaultValue),
			m_minValue(minValue),
			m_maxValue(maxValue)
		{}

		const std::string& getName() const noexcept { return m_name; }
		const std::string& getDescription() const noexcept { return m_description; }
		float getDefaultValue() const noexcept { return m_defaultValue; }
		float getMinValue() const noexcept { return m_minValue; }
		float getMaxValue() const noexcept { return m_maxValue; }

	private:
		std::string m_name;
		std::string m_description;
		float m_defaultValue;
		float m_minValue;
		float m_maxValue;
	};
}
