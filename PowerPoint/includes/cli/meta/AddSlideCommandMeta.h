#pragma once

#include "cli/meta/CommandMeta.h"
#include "core/ActionManager.h"
#include "model/Presentation.h"
#include "cli/factories/slide/AddSlideCommandFactory.h"
#include <memory>

namespace ppt::cli::meta
{
	class AddSlideCommandMeta : public CommandMeta
	{
	public:
		AddSlideCommandMeta(
			core::ActionManager& actionManager,
			model::Presentation& presentation) :
			CommandMeta(
				"add-slide",
				"Adds new slide in the presentation.",
				std::make_shared<AddSlideCommandFactory>(actionManager, presentation),
				std::unordered_map<std::string, ArgInfo>{
					{"-a,--at", {"Position to add the slide at (0-based index). If not specified, adds to the end.", false, ""}},
					{"-c,--color", {"Background color of the new slide (e.g., red, #FF0000). If not specified, uses default color.", false, ""}},
					{"-g,--goto", {"If set, makes the newly added slide the selected slide.", false, "false"}}
		}
				)
		{
		}
	private:
		core::ActionManager& m_actionManager;
		model::Presentation& m_presentation;
	};
}
