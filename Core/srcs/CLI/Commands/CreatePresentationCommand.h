#pragma once

#include "model/AppContext.h"
#include "viewer/IViewer.h"
#include "ConfirmCommand.h"

#include <string>

class CreatePresentationCommand : public ConfirmCommand
{
public:
	CreatePresentationCommand(AppContext& context, const std::string& name);
	Result execute() override;
	Result confirm(bool ans) override;
	std::string confirmQuestion() const override;

private:
	std::string m_name;
};