//#include "cli/errors/InvalidArgumentException.h"
//#include "cli/errors/MissingArgumentException.h"
//#include "cli/factories/shape/RemoveShapeCommandFactory.h"
//#include "cli/utils/ArgParser.h"
//#include "cli/commands/shape/RemoveShapeCommand.h"
//#include "model/utils/Coord.h"
//
//#include <optional>
//
//using namespace ppt::cli;
//using namespace ppt::cli::factories;
//
//std::unique_ptr<cmds::ICommand> RemoveShapeCommandFactory::createCommand(const Arguments& args)
//{
//	std::optional<std::size_t> at;
//	std::optional<std::size_t> shapeId;
//
//	for (const auto& [argName, argVals] : args)
//	{
//		if (argName == "-a" || argName == "--at")
//			at = utils::ArgParser::parseNumber(argName, argVals);
//		else if (argName == "-i" || argName == "--id")
//			shapeId = utils::ArgParser::parseNumber(argName, argVals);
//		else
//			throw err::InvalidArgumentException(argName);
//	}
//
//	if (!shapeId)
//		throw err::MissingArgumentException("-i or --id");
//
//	return std::make_unique<cmds::RemoveShapeCommand>(shapeId.value(), at);
//}