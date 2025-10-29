#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "core/commands/AConfirmCommand.h"

#include <string>

namespace ppt::core::cmds
{
	class CreatePresentationCommand : public AConfirmCommand
	{
	public:
		CreatePresentationCommand(model::AppContext& context, viewer::IViewer& viewer, const std::string& name);
		void execute() override;

	private:
		std::string m_name;
	};
}