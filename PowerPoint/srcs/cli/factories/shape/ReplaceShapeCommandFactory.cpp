#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/MissingArgumentException.h"
#include "cli/factories/shape/ReplaceShapeCommandFactory.h"
#include "cli/utils/ArgParser.h"
#include "cli/commands/shape/ReplaceShapeCommand.h"
#include "model/utils/ShapeType.h"

#include <optional>

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> ReplaceShapeCommandFactory::createCommand(const Arguments& args)
{
	std::optional<std::size_t> at;
	std::optional<std::size_t> shapeId;
	std::optional<model::utils::ShapeType> type;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-t" || argName == "--type")
			type = utils::ArgParser::parseShapeType(argName, argVals);
		else if (argName == "-a" || argName == "--at")
			at = utils::ArgParser::parseNumber(argName, argVals);
		else if (argName == "-i" || argName == "--id")
			shapeId = utils::ArgParser::parseNumber(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	if (!type)
		throw err::MissingArgumentException("-t or --type");
	if (!shapeId)
		throw err::MissingArgumentException("-i or --id");

	return std::make_unique<cmds::ReplaceShapeCommand>(shapeId.value(), type.value(), at);
}