#pragma once

#include "Presentation.h"

#include <memory>
#include <stack>

struct AppContext
{
	std::unique_ptr<Presentation> m_presentation;
	bool m_exit;
};
