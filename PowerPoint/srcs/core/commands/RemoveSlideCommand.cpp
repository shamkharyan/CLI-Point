#include "core/commands/RemoveSlideCommand.h"
#include "model/errors/MissingPresentationException.h"
#include "model/PPModel.h"
#include "viewer/IViewer.h"

#include <stdexcept>

using namespace ppt::model;
using namespace ppt::core::cmds;

RemoveSlideCommand::RemoveSlideCommand(std::optional<std::size_t> at) : m_at(at) {}

void RemoveSlideCommand::execute()
{
	auto& context = PPModel::instance().getContext();
	if (!context.presentation)
		throw err::MissingPresentationException();
	std::size_t count = context.presentation->slidesCount();
	if (!count)
		throw std::runtime_error("Empty presentation");
	if (m_at && m_at.value() < count)
		context.presentation->removeSlide(m_at.value());
	else if (!m_at)
		context.presentation->removeSlide(count - 1);
	else
		throw std::out_of_range("Index out of range");
}
