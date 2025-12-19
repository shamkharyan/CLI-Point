#pragma once

#include <string>

#include "model/utils/ShapeType.h"
#include "model/utils/Color.h"
#include "model/utils/Coord.h"
#include "cli/parsing/factories/ArgValue.h"

namespace ppt::cli
{
	class CLIFormatter
	{
	public:

		static std::string toString(const ArgValue& value);

		static std::string toString(bool value);
		static std::string toString(std::size_t value);
		static std::string toString(float value);
		static std::string toString(model::utils::ShapeType type);
		static std::string toString(model::utils::Coord coord);
		static std::string toHexColorString(model::utils::Color color);
		static std::string toRGBColorString(model::utils::Color color);
		static std::string toColorNameString(model::utils::Color color);
	};
}
