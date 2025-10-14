#include "viewer/CLIViewer.h"
#include <string>
#include <iostream>
#include <optional>

CLIViewer::CLIViewer(std::istream& is, std::ostream& os) :
	m_is(is),
	m_os(os)
{ }

CLIViewer& CLIViewer::instance(std::istream& is, std::ostream& os)
{
	static CLIViewer obj(is, os);
	return obj;
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

void CLIViewer::showPrompt(const std::string& msg)
{
	m_os << msg << " >> ";
}

std::optional<bool> CLIViewer::askConfirmation(const std::string& msg)
{
	char ans;

	showText(msg + " (y/n)");
	showPrompt("");
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

