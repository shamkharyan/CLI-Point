//#include "cli/errors/InvalidArgumentException.h"
//#include "cli/errors/InvalidArgumentValueException.h"
//#include "cli/errors/MissingArgumentValueException.h"
//#include "cli/errors/MissingArgumentException.h"
//#include "cli/factories/slide/MoveSlideCommandFactory.h"
//#include "cli/utils/ArgParser.h"
//#include "cli/commands/slide/MoveSlideCommand.h"
//
//using namespace ppt::cli;
//using namespace ppt::cli::factories;
//
//std::unique_ptr<cmds::ICommand> MoveSlideCommandFactory::createCommand(const Arguments& args)
//{
//	std::optional<std::size_t> at;
//	std::optional<std::size_t> to;
//
//	for (const auto& [argName, argVals] : args)
//	{
//		if (argName == "-a" || "--at")
//			at = utils::ArgParser::parseNumber(argName, argVals);
//		else if (argName == "-t" || "--to")
//			to = utils::ArgParser::parseNumber(argName, argVals);
//		else
//			throw err::InvalidArgumentException(argName);
//	}
//
//	if (!to)
//		throw err::MissingArgumentException("-t or --to");
//
//	return std::make_unique<cmds::MoveSlideCommand>(at, to.value());
//}