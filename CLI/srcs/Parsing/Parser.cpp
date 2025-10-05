//#include "Parser.h"
//#include "ArgVal.h"
//
//Parser::Parser()
//{
//	initCommands();
//}
//
//void Parser::initCommands()
//{
//	Command addSlide("add-slide");
//	addSlide.addArg("-at", ArgVal::Type::NUMBER, true);
//	addSlide.addArg("-bgcolor", ArgVal::Type::COLOR, false);
//	m_commands.insert(addSlide);
//
//	Command addShape("add-shape");
//	addShape.addArg("-type", ArgVal::Type::STRING, true);
//	addShape.addArg("-start", ArgVal::Type::COORD, true);
//	addShape.addArg("-end", ArgVal::Type::COORD, true);
//	addShape.addArg("-w", ArgVal::Type::NUMBER, true);
//	addShape.addArg("-h", ArgVal::Type::NUMBER, true);
//	addShape.addArg("-r", ArgVal::Type::NUMBER, true);
//	addShape.addArg("-bgcolor", ArgVal::Type::COLOR, false);
//	addShape.addArg("-olcolor", ArgVal::Type::COLOR, false);
//	m_commands.insert(addShape);
//
//	Command addText("add-text");
//	addText.addArg("-start", ArgVal::Type::COORD, true);
//	addText.addArg("-size", ArgVal::Type::NUMBER, true);
//	addText.addArg("-color", ArgVal::Type::COLOR, false);
//	addText.addArg("-font", ArgVal::Type::STRING, false);
//	addText.addArg("-style", ArgVal::Type::NUMBER, false);
//	addText.addArg("-link", ArgVal::Type::NUMBER, false);
//	m_commands.insert(addText);
//
//	Command create("create");
//	create.addArg("-name", ArgVal::Type::STRING, false);
//	m_commands.insert(create);
//
//	Command help("help");
//	m_commands.insert(help);
//
//	Command close("close");
//	m_commands.insert(close);
//
//	Command quit("quit");
//	m_commands.insert(quit);
//
//	Command save("save");
//	m_commands.insert(save);
//
//	Command move("move");
//	move.addArg("-id", ArgVal::Type::NUMBER, true);
//	move.addArg("-start", ArgVal::Type::NUMBER, true);
//	move.addArg("-abs", ArgVal::Type::NONE, false);
//	m_commands.insert(move);
//
//	Command del("delete");
//	move.addArg("-id", ArgVal::Type::NUMBER, true);
//	m_commands.insert(del);
//
//	Command gt("goto");
//	gt.addArg("-id", ArgVal::Type::NUMBER, true);
//	m_commands.insert(gt);
//}
//
//bool Parser::evalToken(const std::string& token)
//{
//	if (m_state == State::EMPTY && m_commands.find(token) != m_commands.end())
//	{
//		m_currCommand = token;
//		m_state = State::ARGUMENT;
//	}
//}

#include "AllCommands.h"
#include "Parser.h"
#include "Tokenizer.h"

//std::optional<Command> Parser::parse(std::istream& in)
//{
//	Tokenizer tok(in);
//
//	auto commandName = tok.getNextToken();
//	if (!commandName)
//		return std::nullopt;
//
//
//	parseCommandName();
//	parseCommandArgs();
//
//
//}

std::unique_ptr<Command> Parser::createCommand(const std::string& command)
{
	if (command == "create")
		return std::make_unique<CreateCommand>();
	else if (command == "add-slide")
		return std::make_unique<AddSlideCommand>();
	else if (command == "add-shape")
		return std::make_unique<AddShapeCommand>();
	else if (command == "add-text")
		return std::make_unique<AddTextCommand>();
	else if (command == "help")
		return std::make_unique<HelpCommand>();
	else if (command == "close")
		return std::make_unique<CloseCommand>();
	else if (command == "quit")
		return std::make_unique<QuitCommand>();
	else if (command == "move")
		return std::make_unique<MoveCommand>();
	else if (command == "save")
		return std::make_unique<SaveCommand>();
	else if (command == "open")
		return std::make_unique<OpenCommand>();
	else if (command == "goto")
		return std::make_unique<GotoCommand>();
	else if (command == "delete")
		return std::make_unique<DeleteCommand>();
	return nullptr;
}