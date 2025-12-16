#pragma once

#include <variant>
#include <string>

#include "model/utils/Color.h"

namespace ppt::cli
{
	using ArgValue = std::variant<
		std::string,
		std::size_t,
		float,
		bool,
		ppt::model::utils::Color,
		std::monostate
	>;

	inline std::string argValueToString(const ArgValue& value)
	{
		struct ArgValueToStringVisitor
		{
			std::string operator()(const std::string& str) const
			{
				return str;
			}
			std::string operator()(std::size_t size) const
			{
				return std::to_string(size);
			}
			std::string operator()(float f) const
			{
				return std::to_string(f);
			}
			std::string operator()(bool b) const
			{
				return b ? "true" : "false";
			}
			std::string operator()(const ppt::model::utils::Color& color) const
			{
				return "Color(r=" + std::to_string(color.r) +
					", g=" + std::to_string(color.g) +
					", b=" + std::to_string(color.b) +
					", a=" + std::to_string(color.a) + ")";
			}
			std::string operator()(std::monostate) const
			{
				return "null";
			}
		};
		return std::visit(ArgValueToStringVisitor{}, value);
	}

	inline std::string argValueTypeName(const ArgValue& value)
	{
		struct ArgValueTypeNameVisitor
		{
			std::string operator()(const std::string&) const { return "string"; }
			std::string operator()(std::size_t) const { return "size_t"; }
			std::string operator()(float) const { return "float"; }
			std::string operator()(bool) const { return "bool"; }
			std::string operator()(const ppt::model::utils::Color&) const { return "Color"; }
			std::string operator()(std::monostate) const { return "null"; }
		};
		return std::visit(ArgValueTypeNameVisitor{}, value);
	}
}