#pragma once

#include "CommandRegistry.h"

#include <istream>

class Configuration
{

	std::istream& istream;
	CommandRegistry& registry;
};
