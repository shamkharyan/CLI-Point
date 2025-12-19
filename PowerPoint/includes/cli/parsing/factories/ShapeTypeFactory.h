#pragma once

#include "IArgValueFactory.h"

#include <unordered_map>

namespace ppt::cli
{
	class ShapeTypeFactory : public IArgValueFactory
	{
	public:
		virtual std::optional<ArgValue> tryCreate(const std::vector<std::string>& argValue) const override;
		virtual std::string typeName() const override;
	private:
		const std::unordered_map<std::string, ppt::model::utils::ShapeType> m_shapeTypeMap =
		{
			{"rectangle", ppt::model::utils::ShapeType::Rectangle},
			{"circle", ppt::model::utils::ShapeType::Circle},
			{"triangle", ppt::model::utils::ShapeType::Triangle}
		};
	};
}