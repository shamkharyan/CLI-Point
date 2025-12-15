//#include "cli/errors/InvalidArgumentException.h"
//#include "cli/factories/shape/AddShapeCommandFactory.h"
//#include "cli/utils/ArgParser.h"
//#include "cli/commands/shape/AddShapeCommand.h"
//#include "core/actions/utils/AddShapeParams.h"
//
//using namespace ppt::cli;
//using namespace ppt::cli::factories;
//
//std::unique_ptr<cmds::ICommand> AddShapeCommandFactory::createCommand(const Arguments& args)
//{
//	core::act::utils::AddShapeParams params;
//
//	for (const auto& [argName, argVals] : args)
//	{
//		if (argName == "-t" || argName == "--type")
//			params.type = utils::ArgParser::parseShapeType(argName, argVals);
//		else if (argName == "-p" || argName == "--position")
//			params.position = utils::ArgParser::parseCoord(argName, argVals);
//		else if (argName == "-s" || argName == "--size")
//			params.size = utils::ArgParser::parseCoord(argName, argVals);
//		else if (argName == "-a" || argName == "--at")
//			params.at = utils::ArgParser::parseNumber(argName, argVals);
//		else if (argName == "-c" || argName == "--color")
//			params.bgColor = utils::ArgParser::parseColor(argName, argVals);
//		else if (argName == "--outline-color")
//			params.olColor = utils::ArgParser::parseColor(argName, argVals);
//		else if (argName == "--outline-thickness")
//			params.olThickness = utils::ArgParser::parseNumber(argName, argVals);
//		else if (argName == "--text")
//			params.text = utils::ArgParser::parseString(argName, argVals);
//		else
//			throw err::InvalidArgumentException(argName);
//	}
//
//	return std::make_unique<cmds::AddShapeCommand>(params);
//}