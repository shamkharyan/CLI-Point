#include "cli/factories/slide/RemoveLayerCommandFactory.h"

#include "cli/commands/slide/RemoveLayerCommand.h"

using namespace ppt::cli::factories;
using namespace ppt::cli::cmds;

RemoveLayerCommandFactory::RemoveLayerCommandFactory(
	core::ActionManager& actionManager,
	model::Presentation& presentation) :
	m_actionManager(actionManager),
	m_presentation(presentation)
{
}

std::unique_ptr<ICommand> RemoveLayerCommandFactory::createCommand(const ParsedRawCommand& args)
{
	auto at = std::get<std::size_t>(args.arguments.at("at"));
	auto zIndex = std::get<std::size_t>(args.arguments.at("z-index"));

	return std::make_unique<RemoveLayerCommand>(m_actionManager, m_presentation, at, zIndex);
}