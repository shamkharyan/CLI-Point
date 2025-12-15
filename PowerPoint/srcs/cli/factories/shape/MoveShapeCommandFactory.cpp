//#include "cli/errors/InvalidArgumentException.h"
//#include "cli/errors/MissingArgumentException.h"
//#include "cli/factories/shape/MoveShapeCommandFactory.h"
//#include "cli/utils/ArgParser.h"
//#include "cli/commands/shape/MoveShapeCommand.h"
//#include "model/utils/Coord.h"
//
//#include <optional>
//
//using namespace ppt::cli;
//using namespace ppt::cli::factories;
//
//std::unique_ptr<cmds::ICommand> MoveShapeCommandFactory::createCommand(const Arguments& args)
//{
//	std::optional<std::size_t> at;
//	std::optional<std::size_t> shapeId;
//	std::optional<model::utils::Coord> position;
//
//	for (const auto& [argName, argVals] : args)
//	{
//		if (argName == "-p" || argName == "--position")
//			position = utils::ArgParser::parseCoord(argName, argVals);
//		else if (argName == "-a" || argName == "--at")
//			at = utils::ArgParser::parseNumber(argName, argVals);
//		else if (argName == "-i" || argName == "--id")
//			shapeId = utils::ArgParser::parseNumber(argName, argVals);
//		else
//			throw err::InvalidArgumentException(argName);
//	}
//
//	if (!position)
//		throw err::MissingArgumentException("-p or --position");
//	if (!shapeId)
//		throw err::MissingArgumentException("-i or --id");
//
//	return std::make_unique<cmds::MoveShapeCommand>(shapeId.value(), position.value(), at);
//}