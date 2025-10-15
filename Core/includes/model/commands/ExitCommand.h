#pragma once

#include "model/AppContext.h"
#include "model/commands/AConfirmCommand.h"

class ExitCommand : public AConfirmCommand
{
public:
	ExitCommand(AppContext& context, bool force);
	Result execute() override;
	Result confirm(bool ans) override;
	std::string confirmQuestion() const override;
private:
	bool m_force;
};