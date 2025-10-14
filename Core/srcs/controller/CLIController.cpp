#include "controller/CLIController.h"
#include "controller/parsing/Parser.h"
#include "CommandRegistry.h"
#include "model/PPModel.h"
#include "viewer/CLIViewer.h"
#include "AllCommands.h"

#include <iostream>

CLIController::CLIController(PPModel& model, CLIViewer& viewer) : 
	m_model(model),
	m_viewer(viewer)
{ }

CLIController& CLIController::instance(PPModel& model, CLIViewer& viewer)
{
	static CLIController obj(model, viewer);
	return obj;
}

void CLIController::run()
{
	m_viewer.showText("PowerPoint CLI v0.1");

	registerMainCommands();
	auto& context = m_model.getContext();
	Parser parser(context, m_viewer.getIStream());

	while (!context.exit)
	{
		auto name = (context.presentation) ? context.presentation->getName() : "";
		m_viewer.showPrompt(name);
		try
		{
			std::unique_ptr<Command> cmd = parser.parse();
			if (cmd)
			{
				switch (cmd->execute())
				{
				case Command::Result::Success:
				{
					m_viewer.showInfo("OK");
					break;
				}
				case Command::Result::Confirmation:
				{
					ConfirmCommand* ccmd = dynamic_cast<ConfirmCommand*>(cmd.get());
					auto ans = m_viewer.askConfirmation(ccmd->confirmQuestion());
					if (!ans)
						m_viewer.showInfo("Command Aborted");
					else
					{
						switch (ccmd->confirm(ans.value()))
						{
						case Command::Result::Success:
							m_viewer.showInfo("OK");
							break;
						case Command::Result::Fail:
							m_viewer.showError("Command Failed");
							break;
						default:
							m_viewer.showError("Undefined Error");
							break;
						}
					}
					break;
				}
				case Command::Result::Fail:
				{
					m_viewer.showError("Command Failed");
					break;
				}
				default:
				{
					m_viewer.showError("Undefined Error");
					break;
				}
				}
			}
			else
				m_viewer.showInfo("Empty input");
		}
		catch (const std::runtime_error& e)
		{
			m_viewer.showError(e.what());
			m_viewer.resetStream();
		}
	}
}