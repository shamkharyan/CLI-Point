#include "cli/CLIViewer.h"
#include "model/Presentation.h"

#include <iostream>
#include <iomanip>
#include <optional>
#include <string>

using namespace ppt::cli;

CLIViewer::CLIViewer(model::Presentation& presentation, std::istream& is, std::ostream& os) :
	m_presentation(presentation),
	m_is(is),
	m_os(os)
	//m_visualizer(os)
{
}

void CLIViewer::showError(const std::string& msg)
{
	m_os << "[ERROR] " << msg << '\n';
}

void CLIViewer::showWarning(const std::string& msg)
{
	m_os << "[WARNING] " << msg << '\n';
}

void CLIViewer::showInfo(const std::string& msg)
{
	m_os << "[INFO] " << msg << '\n';
}

std::optional<bool> CLIViewer::askConfirmation(const std::string& msg)
{
	char ans;

	showText(msg + " (y/n): ");
	m_is.get(ans);
	resetStream();
	switch (std::tolower(ans))
	{
	case 'y':
		return true;
	case 'n':
		return false;
	}
	return std::nullopt;
}

//CLIVisualizer& CLIViewer::getVisualizer()
//{
//	return m_visualizer;
//}

std::istream& CLIViewer::getIStream()
{
	return m_is;
}

std::ostream& CLIViewer::getOStream()
{
	return m_os;
}

void CLIViewer::resetStream()
{
	m_is.clear();
	if (m_is.rdbuf()->in_avail() != 0)
		m_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void CLIViewer::showText(const std::string& msg)
{
	m_os << msg << '\n';
}

void CLIViewer::showPrompt()
{
	m_os << m_presentation.getName() << " >> ";
}

void CLIViewer::showWelcome()
{
	m_os << R"(  /$$$$$$  /$$       /$$$$$$       /$$$$$$$   /$$$$$$  /$$$$$$ /$$   /$$ /$$$$$$$$)" << '\n';
	m_os << R"( /$$__  $$| $$      |_  $$_/      | $$__  $$ /$$__  $$|_  $$_/| $$$ | $$|__  $$__/)" << '\n';
	m_os << R"(| $$  \__/| $$        | $$        | $$  \ $$| $$  \ $$  | $$  | $$$$| $$   | $$   )" << '\n';
	m_os << R"(| $$      | $$        | $$ /$$$$$$| $$$$$$$/| $$  | $$  | $$  | $$ $$ $$   | $$   )" << '\n';
	m_os << R"(| $$      | $$        | $$|______/| $$____/ | $$  | $$  | $$  | $$  $$$$   | $$   )" << '\n';
	m_os << R"(| $$    $$| $$        | $$        | $$      | $$  | $$  | $$  | $$\  $$$   | $$   )" << '\n';
	m_os << R"(|  $$$$$$/| $$$$$$$$ /$$$$$$      | $$      |  $$$$$$/ /$$$$$$| $$ \  $$   | $$   )" << '\n';
	m_os << R"( \______/ |________/|______/      |__/       \______/ |______/|__/  \__/   |__/   )" << '\n';
	m_os << R"(                                                                                  )" << '\n';
	m_os << R"(Welcome to CLI-Point! For help type "help"                                        )" << '\n';
}

void CLIViewer::showArgumentsHelp(const meta::CommandMeta& cmdMeta)
{
	if (cmdMeta.begin() == cmdMeta.end())
		return;

	m_os << "ARGUMENTS:\n";
	for (const auto& argMeta : cmdMeta)
	{
		std::string aliases;
		for (const auto& alias : argMeta.getNameAliases())
			aliases += alias + " ";

		m_os << " " << std::setw(s_columnWidth) << std::left << aliases << argMeta.getDescription() << '\n';
		m_os << " " << std::string(s_columnWidth, ' ') <<
			std::setw(s_columnWidth) << std::left << (*argMeta.begin())->typeName();

		m_os << (argMeta.isRequired() ? " (required) " : " (optional) ");
		m_os << (argMeta.hasDefaultValue() ?
			" [default: " + argValueToString(argMeta.getDefaultValue()) + "]" : "");
		m_os << '\n';
	}
}

void CLIViewer::showCommandDescription(const meta::CommandMeta& cmdMeta)
{
	m_os << "DESCRIPTION:\n";
	m_os << " " << cmdMeta.getDescription() << "\n\n";
}

void CLIViewer::showCommandHelp(const meta::CommandMeta& cmdMeta)
{
	showCommandUsage(cmdMeta);
	showCommandDescription(cmdMeta);
	showArgumentsHelp(cmdMeta);
}

void CLIViewer::showCommandUsage(const meta::CommandMeta& cmdMeta)
{
	m_os << "USAGE:\n";
	m_os << " " << cmdMeta.getName();
	for (const auto& argMeta : cmdMeta)
	{
		m_os << " ";
		if (!argMeta.isRequired())
			m_os << "[";
		else
			m_os << "<";
		m_os << argMeta.getCanonicalName();
		if (!argMeta.isRequired())
			m_os << "]";
		else
			m_os << ">";
	}
	m_os << "\n\n";
}

void CLIViewer::showHelp(const CommandRegistry& registry)
{
	m_os << "AVAILABLE COMMANDS:\n";
	for (const auto& cmdMeta : registry)
	{
		showCommandHelp(cmdMeta);
		m_os << " " << std::string(s_columnWidth * 3, '-') << '\n';
	}
}