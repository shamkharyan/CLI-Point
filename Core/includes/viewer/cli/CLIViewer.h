#pragma once

#include "viewer/IViewer.h"

#include <string>
#include <optional>

namespace ppt::viewer::cli
{
	class CLIViewer : public IViewer
	{
	public:
		static CLIViewer& instance(std::istream& m_is, std::ostream& m_os);
		void showError(const std::string& msg) override;
		void showWarning(const std::string& msg) override;
		void showInfo(const std::string& msg) override;
		std::optional<bool> askConfirmation(const std::string& msg) override;

		void showPrompt(const std::string& msg = "(no data)");
		void showText(const std::string& msg);
		void resetStream();

		std::istream& getIStream();
		std::ostream& getOStream();
	private:
		CLIViewer(std::istream& is, std::ostream& os);
		CLIViewer(const CLIViewer&) = delete;
		CLIViewer(CLIViewer&&) noexcept = delete;
		CLIViewer& operator=(CLIViewer&&) noexcept = delete;
		CLIViewer& operator=(const CLIViewer&) = delete;
	private:
		std::istream& m_is;
		std::ostream& m_os;
	};
}
