#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "AConfirmCommand.h"

#include <string>

class CreatePresentationCommand : public AConfirmCommand
{
public:
	CreatePresentationCommand(AppContext& context, IViewer& viewer, const std::string& name);
	void execute() override;

private:
	std::string m_name;
};