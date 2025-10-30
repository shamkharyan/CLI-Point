#pragma once

#include "viewer/IViewer.h"
#include "viewer/cli/CLIVisualizer.h"

#include <optional>
#include <string>

namespace ppt::viewer::cli
{
	class CLIViewer : public IViewer
	{
	public:
		CLIViewer(std::istream& is, std::ostream& os);
		void showError(const std::string& msg) override;
		void showWarning(const std::string& msg) override;
		void showInfo(const std::string& msg) override;
		std::optional<bool> askConfirmation(const std::string& msg) override;

		void showPrompt(std::shared_ptr<model::Presentation> presentation);
		void showText(const std::string& msg);
		void showWelcome();
		void resetStream();

		CLIVisualizer& getVisualizer();
		std::istream& getIStream();
		std::ostream& getOStream();
	private:
		CLIVisualizer m_visualizer;
		std::istream& m_is;
		std::ostream& m_os;
	};
}
