#include "cli/CLIViewer.h"
#include "cli/CLIFormatter.h"
#include "model/Presentation.h"

#include <iostream>
#include <iomanip>
#include <optional>
#include <string>

using namespace ppt::cli;

namespace
{
	void printArgument(
		std::ostream& os,
		const ppt::cli::meta::ArgumentMeta& argMeta,
		std::size_t indent = 1
	)
	{
		const std::size_t columnWidth = 20;
		const std::string pad(indent * 2, ' ');

		// aliases
		std::string aliases;
		for (const auto& alias : argMeta.getNameAliases())
			aliases += alias + " ";

		if (aliases.empty())
			aliases = "--" + argMeta.getCanonicalName();

		aliases = pad + aliases;

		// type
		std::string typeName = "group";
		if (!argMeta.getValueFactories().empty())
			typeName = argMeta.getValueFactories().front()->typeName();

		// main argument line
		os << std::left
			<< std::setw(columnWidth) << aliases
			<< argMeta.getDescription();

		if (!argMeta.getValueFactories().empty())
			os << " (" << typeName << ")";

		os << '\n';

		// required / default
		os << std::string(columnWidth, ' ') << pad
			<< (argMeta.isRequired() ? "required" : "optional");

		if (auto def = argMeta.getDefaultValue())
			os << "  [default: " << CLIFormatter::toString(*def) << "]";

		os << "\n\n";

		// specifications (valueSpecGroups)
		if (argMeta.hasValueSpecGroups())
		{
			os << std::string(columnWidth, ' ') << "SPECIFICATIONS:\n";

			for (const auto& group : argMeta.getValueSpecGroups())
			{
				os << std::string(columnWidth + 2, ' ') << group.name << '\n';

				for (const auto& item : group.items)
				{
					os << std::string(columnWidth + 4, ' ')
						<< std::left << std::setw(16)
						<< item.name
						<< item.description;

					os << " [default: " << CLIFormatter::toString(item.defaultValue) << "]";

					os << '\n';
				}
				os << '\n';
			}
		}
	}
}

CLIViewer::CLIViewer(model::Presentation& presentation, std::istream* is, std::ostream* os) :
	m_presentation(presentation),
	m_is(is),
	m_os(os)
{
}

void CLIViewer::setIStream(std::istream* is)
{
	m_is = is;
}

void CLIViewer::setOStream(std::ostream* os)
{
	m_os = os;
}

void CLIViewer::showError(const std::string& msg)
{
	*m_os << "[ERROR] " << msg << '\n';
}

void CLIViewer::showWarning(const std::string& msg)
{
	*m_os << "[WARNING] " << msg << '\n';
}

void CLIViewer::showInfo(const std::string& msg)
{
	*m_os << "[INFO] " << msg << '\n';
}

std::optional<bool> CLIViewer::askConfirmation(const std::string& msg)
{
	char ans;

	showText(msg + " (y/n): ");
	m_is->get(ans);
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

std::istream* CLIViewer::getIStream()
{
	return m_is;
}

std::ostream* CLIViewer::getOStream()
{
	return m_os;
}

void CLIViewer::resetStream()
{
	m_is->clear();
	if (m_is->rdbuf()->in_avail() != 0)
		m_is->ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void CLIViewer::showText(const std::string& msg)
{
	*m_os << msg << '\n';
}

void CLIViewer::showPrompt()
{
	*m_os << m_presentation.getName() << " >> ";
}

void CLIViewer::showWelcome()
{
	*m_os << R"(  /$$$$$$  /$$       /$$$$$$       /$$$$$$$   /$$$$$$  /$$$$$$ /$$   /$$ /$$$$$$$$)" << '\n';
	*m_os << R"( /$$__  $$| $$      |_  $$_/      | $$__  $$ /$$__  $$|_  $$_/| $$$ | $$|__  $$__/)" << '\n';
	*m_os << R"(| $$  \__/| $$        | $$        | $$  \ $$| $$  \ $$  | $$  | $$$$| $$   | $$   )" << '\n';
	*m_os << R"(| $$      | $$        | $$ /$$$$$$| $$$$$$$/| $$  | $$  | $$  | $$ $$ $$   | $$   )" << '\n';
	*m_os << R"(| $$      | $$        | $$|______/| $$____/ | $$  | $$  | $$  | $$  $$$$   | $$   )" << '\n';
	*m_os << R"(| $$    $$| $$        | $$        | $$      | $$  | $$  | $$  | $$\  $$$   | $$   )" << '\n';
	*m_os << R"(|  $$$$$$/| $$$$$$$$ /$$$$$$      | $$      |  $$$$$$/ /$$$$$$| $$ \  $$   | $$   )" << '\n';
	*m_os << R"( \______/ |________/|______/      |__/       \______/ |______/|__/  \__/   |__/   )" << '\n';
	*m_os << R"(                                                                                  )" << '\n';
	*m_os << R"(Welcome to CLI-Point! For help type "help"                                        )" << '\n';
}

void CLIViewer::showArgumentsHelp(const meta::CommandMeta& cmdMeta)
{
	if (cmdMeta.begin() == cmdMeta.end())
		return;

	*m_os << "\nARGUMENTS:\n\n";

	for (const auto& argMeta : cmdMeta)
		printArgument(*m_os, argMeta, 0);
}

void CLIViewer::showCommandDescription(const meta::CommandMeta& cmdMeta)
{
	*m_os << "DESCRIPTION:\n";
	*m_os << " " << cmdMeta.getDescription() << "\n";
}

void CLIViewer::showCommandHelp(const meta::CommandMeta& cmdMeta)
{
	showCommandUsage(cmdMeta);
	showCommandDescription(cmdMeta);
	showArgumentsHelp(cmdMeta);
}

void CLIViewer::showCommandUsage(const meta::CommandMeta& cmdMeta)
{
	*m_os << "USAGE:\n";
	*m_os << " " << cmdMeta.getName();
	for (const auto& argMeta : cmdMeta)
	{
		*m_os << " ";
		if (!argMeta.isRequired())
			*m_os << "[";
		else
			*m_os << "<";
		*m_os << argMeta.getCanonicalName();
		if (!argMeta.isRequired())
			*m_os << "]";
		else
			*m_os << ">";
	}
	*m_os << "\n\n";
}

void CLIViewer::showHelp(const CommandRegistry& registry)
{
	*m_os << "AVAILABLE COMMANDS:\n";
	for (const auto& cmdMeta : registry)
	{
		showCommandHelp(cmdMeta);
		*m_os << " " << std::string(s_columnWidth * 3, '-') << '\n';
	}
}