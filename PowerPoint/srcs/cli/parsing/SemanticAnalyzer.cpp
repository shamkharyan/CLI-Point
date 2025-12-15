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

	for (const auto& argMeta : *cmdMeta)
	{
		const auto& canonical = argMeta.getCanonicalName();
		const bool isPresent =
			validatedCmd.arguments.find(canonical) != validatedCmd.arguments.end();

		if (!isPresent)
		{
			if (argMeta.isRequired())
			{
				throw SemanticException(
					"Required argument '" + argMeta.getNameAliases()[0] +
					"' is missing for command '" + rcmd.name + "'");
			}

			if (auto optionalDefault = argMeta.getDefaultValue())
				validatedCmd.arguments[canonical] = *optionalDefault;
		}
	}

	return validatedCmd;
}