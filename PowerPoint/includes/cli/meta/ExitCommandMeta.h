#pragma once

#include "cli/meta/CommandMeta.h"
#include "cli/factories/utility/ExitCommandFactory.h"
#include "viewer/cli/CLIViewer.h"
#include "cli/CLIController.h"

namespace ppt::cli::meta
{
	class ExitCommandMeta : public CommandMeta
	{
	public:
		ExitCommandMeta(CLIController& controller, viewer::cli::CLIViewer& viewer) :
			CommandMeta(
				"exit",
				"Exits the application.",
				std::make_shared<factories::ExitCommandFactory>(controller, viewer),
				std::unordered_map<std::string, ArgInfo>
				{ 
					{
						"-f", 
						ArgInfo
						{
							"Force exit",
							false,
							""
						}
					},
					{
						"--force",
						ArgInfo
						{
							"Force exit",
							false,
							""
						}
					}
				}
			)
		{
		}
	};
}
