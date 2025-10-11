#pragma once

#include "model/AppContext.h"
#include "CommandRegistry.h"

class CLIController
{
public:
	static CLIController& instance();
	void run();
private:
	CLIController() = default;
	CLIController(const CLIController&) = delete;
	CLIController(CLIController&&) noexcept = delete;
	CLIController& operator=(const CLIController&) = delete;
	CLIController& operator=(CLIController&&) noexcept = delete;
private:
	AppContext m_context;
};