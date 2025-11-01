//#include "cli/errors/InvalidArgumentException.h"
//#include "cli/factories/AddShapeCommandFactory.h"
//#include "cli/utils/ArgParser.h"
//#include "cli/commands/AddShapeCommand.h"
//#include "model/utils/ShapeType.h"
//#include "model/utils/Coord.h"
//#include "model/utils/Geometry.h"
//
//using namespace ppt::cli;
//using namespace ppt::cli::factories;
//
//std::unique_ptr<cmds::ICommand> AddShapeCommandFactory::createCommand(const Arguments& args)
//{
//	model::
//	std::optional<model::utils::ShapeType> type;
//	std::optional<model::utils::Coord> position;
//	std::optional<model::utils::Coord> size;
//
//	for (const auto& [argName, argVals] : args)
//	{
//		if (argName == "-t" || argName == "--type")
//			type = utils::ArgParser::parseShapeType(argName, argVals);
//		else if (argName == "-p" || argName == "--position")
//			position = utils::ArgParser::parseCoord(argName, argVals);
//		else if (argName == "-s" || argName == "--size")
//			size = utils::ArgParser::parseCoord(argName, argVals);
//		else if (argName == "-r" || argName == "--rotation")
//			/* logic */;
//		else if (argName == "-z" || argName == "--z-index")
//			/* logic */;
//		else if (argName == "-c" || argName == "--color")
//			/* logic */;
//		else if (argName == "-a" || argName == "--opacity")
//			/* logic */;
//		else if (argName == "--outline-color")
//			/* logic */;
//		else if (argName == "--outline-thickness")
//			/* logic */;
//		else if (argName == "--outline-type")
//			/* logic */;
//		else if (argName == "--text")
//			/* logic */;
//		else if (argName == "--text-color")
//			/* logic */;
//		else if (argName == "--text-font")
//			/* logic */;
//		else if (argName == "--font-style")
//			/* logic */;
//		else if (argName == "--font-weight")
//			/* logic */;
//		else if (argName == "--font-size")
//			/* logic */;
//		else
//			throw err::InvalidArgumentException(argName);
//	}
//
//	return std::make_unique<cmds::AddSlideCommand>(/* ??? */);
//}