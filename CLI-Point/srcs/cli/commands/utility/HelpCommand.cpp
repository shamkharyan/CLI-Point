#include "cli/commands/utility/HelpCommand.h"

using namespace ppt::cli::cmds;

HelpCommand::HelpCommand(CommandRegistry& registry, CLIViewer& viewer, const std::string& specificCommandName) :
	m_registry(registry),
	m_viewer(viewer),
	m_specificCommandName(specificCommandName)
{
}

void HelpCommand::execute()
{
	if (!m_specificCommandName.empty())
	{
		const auto cmdMeta = m_registry.getCommandMeta(m_specificCommandName);
		if (!cmdMeta)
		{
			m_viewer.showError("Unknown command: " + m_specificCommandName);
			return;
		}
		m_viewer.showCommandHelp(*cmdMeta);
	}
	else
		m_viewer.showHelp(m_registry);
}