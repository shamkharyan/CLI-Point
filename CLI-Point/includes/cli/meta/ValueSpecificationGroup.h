#pragma once

#include <vector>
#include <string>

#include "ValueSpecification.h"

namespace ppt::cli::meta
{
	struct ValueSpecificationGroup
	{
		std::string name;
		std::vector<ValueSpecification> items;
	};
}
