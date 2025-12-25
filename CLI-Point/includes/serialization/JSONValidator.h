#pragma once

#include "IValidator.h"

#include "libs/json.hpp"

namespace ppt::ser
{
	class JSONValidator : public IValidator
	{
		using json = nlohmann::json;
	public:
		bool validate(const std::string& filePath) const override;
	private:
		bool validatePresentation(const json& jPresentation) const;
		bool validateSlide(const json& jSlide) const;
		bool validateShape(const json& jShape) const;
		bool validateColor(const json& jColor) const;
	};
}