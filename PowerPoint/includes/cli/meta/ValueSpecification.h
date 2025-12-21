#pragma once

#include "cli/parsing/parsers/ArgValue.h"

#include <string>

namespace ppt::cli::meta
{
	struct ValueSpecification
	{
		std::string name;
		std::string description;
		ArgValue defaultValue;
	};
}
