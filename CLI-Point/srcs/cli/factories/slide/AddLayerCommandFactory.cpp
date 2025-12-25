#include "cli/factories/slide/AddLayerCommandFactory.h"

#include "cli/commands/slide/AddLayerCommand.h"

using namespace ppt::cli;
using namespace ppt::cli::factories;

AddLayerCommandFactory::AddLayerCommandFactory(
	core::ActionManager& actionManager,
	model::Presentation& presentation) :
	m_actionManager(actionManager),
	m_presentation(presentation)
{
}

std::unique_ptr<cmds::ICommand> AddLayerCommandFactory::createCommand(const ParsedRawCommand& args)
{
	auto at = std::get<std::size_t>(args.arguments.at("at"));
	auto zIndex = std::get<std::size_t>(args.arguments.at("z-index"));

	return std::make_unique<cmds::AddLayerCommand>(m_actionManager, m_presentation, at, zIndex);
}