#pragma once

#pragma once

#include "IArgValueFactory.h"

#include <unordered_map>

namespace ppt::cli
{
	class ColorNameFactory : public IArgValueFactory
	{
	public:
		virtual std::optional<ArgValue> tryCreate(const std::vector<std::string>& argValue) const override;
		virtual std::string typeName() const override;
		private:
			const std::unordered_map<std::string, ppt::model::utils::Color> m_colorMap = {
				{"black", ppt::model::utils::Color(0, 0, 0)},
				{"white", ppt::model::utils::Color(255, 255, 255)},
				{"red", ppt::model::utils::Color(255, 0, 0)},
				{"green", ppt::model::utils::Color(0, 255, 0)},
				{"blue", ppt::model::utils::Color(0, 0, 255)},
				{"yellow", ppt::model::utils::Color(255, 255, 0)},
				{"cyan", ppt::model::utils::Color(0, 255, 255)},
				{"magenta", ppt::model::utils::Color(255, 0, 255)},
				{"gray", ppt::model::utils::Color(128, 128, 128)},
				{"orange", ppt::model::utils::Color(255, 165, 0)},
				{"purple", ppt::model::utils::Color(128, 0, 128)},
				{"pink", ppt::model::utils::Color(255, 192, 203)}
			};
	};
}
