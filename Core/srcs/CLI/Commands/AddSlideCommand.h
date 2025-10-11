#pragma once

#include "Command.h"

#include <optional>

class AddSlideCommand : public Command
{
public:
	AddSlideCommand();

private:
	std::optional<std::size_t> m_id;
};
