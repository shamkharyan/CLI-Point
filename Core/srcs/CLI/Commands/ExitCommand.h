#pragma once

#include "model/AppContext.h"
#include "ConfirmCommand.h"

class ExitCommand : public ConfirmCommand
{
public:
	ExitCommand(AppContext& context, bool force);
	Result execute() override;
	Result confirm(bool ans) override;
	std::string confirmQuestion() const override;
private:
	bool m_force;
};