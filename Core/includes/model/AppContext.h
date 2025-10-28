#pragma once

#include "model/Presentation.h"

#include <memory>
#include <stack>

namespace ppt::model
{
	struct AppContext
	{
		std::unique_ptr<Presentation> presentation;
		bool exit = false;
	};
}
