#include "cli/errors/InvalidArgumentException.h"
#include "cli/errors/MissingArgumentException.h"
#include "cli/factories/shape/ResizeShapeCommandFactory.h"
#include "cli/utils/ArgParser.h"
#include "cli/commands/shape/ResizeShapeCommand.h"
#include "model/utils/Coord.h"

#include <optional>

using namespace ppt::cli;
using namespace ppt::cli::factories;

std::unique_ptr<cmds::ICommand> ResizeShapeCommandFactory::createCommand(const Arguments& args)
{
	std::optional<std::size_t> at;
	std::optional<std::size_t> shapeId;
	std::optional<model::utils::Coord> size;

	for (const auto& [argName, argVals] : args)
	{
		if (argName == "-s" || argName == "--size")
			size = utils::ArgParser::parseCoord(argName, argVals);
		else if (argName == "-a" || argName == "--at")
			at = utils::ArgParser::parseNumber(argName, argVals);
		else if (argName == "-i" || argName == "--id")
			shapeId = utils::ArgParser::parseNumber(argName, argVals);
		else
			throw err::InvalidArgumentException(argName);
	}

	if (!size)
		throw err::MissingArgumentException("-s or --size");
	if (!shapeId)
		throw err::MissingArgumentException("-i or --id");

	return std::make_unique<cmds::ResizeShapeCommand>(shapeId.value(), size.value(), at);
}