#pragma once

#include "model/utils/Color.h"

#include <optional>
#include <string>
#include <vector>

namespace ppt::cli::utils
{
	class Converter
	{
	public:
		static std::optional<std::size_t> stringToSizeT(const std::string& str);
		static std::optional<model::utils::Color> stringToColor(const std::string& str);
		static std::optional<model::utils::Color> vectorToColor(const std::vector<std::string>& vec);
	private:
		Converter() = delete;
		Converter(const Converter&) = delete;
		Converter(Converter&&) noexcept = delete;
		Converter& operator=(const Converter&) = delete;
		Converter& operator=(Converter&&) noexcept = delete;
	};
}