#include "cli/parsing/SemanticAnalizer.h"
#include "cli/parsing/errors/SemanticException.h"

using namespace ppt::cli;

SemanticAnalyzer::SemanticAnalyzer(const CommandRegistry& registry) :
	commandRegistry(registry)
{
}

ValidatedRawCommand SemanticAnalyzer::analyze(const RawCommand& rcmd)
{
	auto cmdMeta = commandRegistry.getCommandMeta(rcmd.name);
	if (!cmdMeta)
		throw SemanticException("Unknown command: " + rcmd.name);

	ValidatedRawCommand validatedCmd;
	validatedCmd.name = rcmd.name;

	for (const auto& [argName, argValue] : rcmd.arguments)
	{
		auto argMeta = cmdMeta->getArgumentMeta(argName);
		if (!argMeta)
			throw SemanticException("Unknown argument '" + argName + "' for command '" + rcmd.name + "'");
		if (!argMeta->isValidValue(argValue))
			throw SemanticException("Invalid value for argument '" + argName + "' in command '" + rcmd.name + "'");
		validatedCmd.arguments[argMeta->getCanonicalName()] = argMeta->parseValue(argValue);
	}

	return validatedCmd;
}