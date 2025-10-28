#include "core/commands/AddSlideCommand.h"
#include "model/errors/MissingPresentationException.h"
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
		throw err::MissingPresentationException();
	std::size_t count = context.presentation->slidesCount();
	if (m_at && m_at.value() < count)
		context.presentation->addSlide(std::make_unique<Slide>(m_bgColor), m_at.value());
	else if (!m_at)
		context.presentation->addSlide(std::make_unique<Slide>(m_bgColor), count);
	else
		throw std::out_of_range("Index out of bounds");
}
