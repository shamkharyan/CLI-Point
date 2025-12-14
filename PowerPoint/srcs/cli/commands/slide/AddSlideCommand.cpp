#include "cli/commands/slide/AddSlideCommand.h"
#include "viewer/IViewer.h"
#include "core/ActionManager.h"
#include "core/actions/slide/AddSlideAction.h"

#include <stdexcept>

using namespace ppt::core;
using namespace ppt::cli::cmds;
using namespace ppt::model;

void AddSlideCommand::execute()
{
	auto slide = std::make_shared<Slide>();
	auto action = std::make_unique<act::AddSlideAction>(m_at, m_color, m_goto);
	if (action->doAction())
		m_actionManager.append(std::move(action));
}
