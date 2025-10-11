#include "controller/CLIController.h"
#include "controller/parsing/Parser.h"
#include "CommandRegistry.h"

#include <iostream>

CLIController& CLIController::instance()
{
	static CLIController obj;
	return obj;
}

void CLIController::run()
{
	registerMainCommands();
	Parser parser(m_context, std::cin);

	while (!m_context.m_exit)
	{
		try
		{
			std::cout << ">> ";
			std::unique_ptr<Command> cmd = parser.parse();
			cmd->execute();
			std::cout << "OK\n";
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what() << '\n';
			parser.resetStream();
		}
	}
}

