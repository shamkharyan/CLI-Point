#pragma once

#include "model/utils/Color.h"
#include "model/utils/Coord.h"

#include <optional>
#include <string>
#include <vector>

namespace ppt::cli::utils
{
	class ArgParser
	{
	public:
		static bool parseFlag(const std::string& argName, const std::vector<std::string>& argVal);
		static model::utils::Color parseColor(const std::string& argName, const std::vector<std::string>& argVal);
		static model::utils::Coord parseCoord(const std::string& argName, const std::vector<std::string>& argVal);
		static std::size_t parseNumber(const std::string& argName, const std::vector<std::string>& argVal);
		static std::string parseString(const std::string& argName, const std::vector<std::string>& argVal);
	private:
		ArgParser() = delete;
		ArgParser(const ArgParser&) = delete;
		ArgParser(ArgParser&&) noexcept = delete;
		ArgParser& operator=(const ArgParser&) = delete;
		ArgParser& operator=(ArgParser&&) noexcept = delete;
	};
}