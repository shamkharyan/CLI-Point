#include "cli/parsing/SemanticParser.h"
#include "cli/parsing/errors/SemanticException.h"

using namespace ppt::cli;

SemanticParser::SemanticParser(const CommandRegistry& registry) :
	commandRegistry(registry)
{
}

ParsedRawCommand SemanticParser::parseRawCommand(const RawCommand& rcmd)
{
	auto cmdMeta = commandRegistry.getCommandMeta(rcmd.name);
	if (!cmdMeta)
		throw SemanticException("Unknown command: " + rcmd.name);

	ParsedRawCommand parsedCmd;
	parsedCmd.name = rcmd.name;

	for (const auto& [argName, argValue] : rcmd.arguments)
	{
		const auto argMeta = cmdMeta->getArgumentMeta(argName);
		if (!argMeta)
			throw SemanticException("Unknown argument '" + argName + "' for command '" + rcmd.name + "'");

		bool isParsed = false;
		for (const auto& valueFactory : *argMeta)
		{
			if (valueFactory->canCreate(argValue))
			{
				parsedCmd.arguments[argMeta->getCanonicalName()] = valueFactory->create(argValue);
				isParsed = true;
				break;
			}
		}
		if (!isParsed)
			throw SemanticException("Invalid value for argument '" + argName + "' in command '" + rcmd.name + "'");
	}

	for (const auto& argMeta : *cmdMeta)
	{
		const auto& canonical = argMeta.getCanonicalName();
		const bool isPresent =
			parsedCmd.arguments.find(canonical) != parsedCmd.arguments.end();

		if (!isPresent)
		{
			if (argMeta.isRequired())
			{
				throw SemanticException(
					"Required argument '" + argMeta.getNameAliases()[0] +
					"' is missing for command '" + rcmd.name + "'");
			}
			if (argMeta.hasDefaultValue())
				parsedCmd.arguments[canonical] = argMeta.getDefaultValue();
		}
	}

	return parsedCmd;
}