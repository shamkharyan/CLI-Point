#include "cli/parsing/factories/CoordFactory.h"
#include "model/utils/Coord.h"

using namespace ppt::cli;

std::optional<ArgValue> CoordFactory::tryCreate(const std::vector<std::string>& argValue) const
{
	if (argValue.size() != 2)
		return std::nullopt;

	try
	{
		std::size_t idx1 = 0;
		std::size_t idx2 = 0;
		std::size_t x = std::stoull(argValue[0], &idx1);
		std::size_t y = std::stoull(argValue[1], &idx2);
		if (idx1 != argValue[0].size() || idx2 != argValue[1].size())
			return std::nullopt;
		return model::utils::Coord(x, y);
	}
	catch (const std::exception&)
	{
		return std::nullopt;
	}
}

std::string CoordFactory::typeName() const
{
	return "Coord";
}