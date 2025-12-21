#pragma once

#include "IArgValueParser.h"

#include "visualization/meta/ShapeRegistry.h"

namespace ppt::cli
{
	class ShapeTypeParser : public IArgValueParser
	{
	public:
		explicit ShapeTypeParser(const vis::ShapeRegistry& registry);

		virtual std::optional<ArgValue> tryCreate(const std::vector<std::string>& argValue) const override;
		virtual std::string typeName() const override;

	private:
		const vis::ShapeRegistry& m_registry;
	};
}