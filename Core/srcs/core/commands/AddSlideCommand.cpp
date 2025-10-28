#include "core/commands/AddSlideCommand.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"

#include <stdexcept>

using namespace ppt::model;
using namespace ppt::core::cmds;

AddSlideCommand::AddSlideCommand(std::optional<std::size_t> at, utils::Color bgColor) :
	m_at(at),
	m_bgColor(bgColor)
{ }

void AddSlideCommand::execute()
{
	auto& context = PPModel::instance().getContext();
	if (!context.presentation)
		throw std::runtime_error("No presentation for adding a slide");
	if (!m_at)
		context.presentation->addSlide(std::make_unique<Slide>(), context.presentation->slidesCount());
	else
		context.presentation->addSlide(std::make_unique<Slide>(), m_at.value());
}
