#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "controller/commands/ACommand.h"

#include <string>
#include <optional>

class AddSlideCommand : public ACommand
{
public:
	AddSlideCommand(AppContext& context, std::optional<std::size_t> at, Color bgColor);
	void execute() override;

private:
	std::optional<std::size_t> m_at;
	Color m_bgColor;
};
