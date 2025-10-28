#include "core/commands/RemoveSlideCommand.h"

#include "model/PPModel.h"
#include "viewer/IViewer.h"

#include <stdexcept>

using namespace ppt::model;
using namespace ppt::core::cmds;

RemoveSlideCommand::RemoveSlideCommand(std::size_t at) : m_at(at) {}

void RemoveSlideCommand::execute()
{
	auto& context = PPModel::instance().getContext();
	if (!context.presentation)
		throw std::runtime_error("No presentation for removing a slide");
	context.presentation->removeSlide(m_at);
}
