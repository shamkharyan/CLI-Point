#pragma once

#include "model/presentation/Presentation.h"

#include <memory>
#include <stack>

struct AppContext
{
	std::unique_ptr<Presentation> presentation;
	bool exit = false;
};
