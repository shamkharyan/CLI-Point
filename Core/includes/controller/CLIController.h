#pragma once

#include "controller/IController.h"
#include "model/AppContext.h"
#include "CommandRegistry.h"
#include "viewer/CLIViewer.h"
#include "model/PPModel.h"

class CLIController : public IController
{
public:
	static CLIController& instance(PPModel& model, CLIViewer& viewer);
	void run() override;
private:
	CLIController(PPModel& model, CLIViewer& viewer);
	CLIController(const CLIController&) = delete;
	CLIController(CLIController&&) noexcept = delete;
	CLIController& operator=(const CLIController&) = delete;
	CLIController& operator=(CLIController&&) noexcept = delete;

	void registerMainCommands();
private:
	PPModel& m_model;
	CLIViewer& m_viewer;
};