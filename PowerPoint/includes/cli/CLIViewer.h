#pragma once

#include "core/IViewer.h"
//#include "viewer/cli/CLIVisualizer.h"
#include "model/Presentation.h"

#include <optional>
#include <string>

namespace ppt::cli
{
	class CLIViewer : public core::IViewer
	{
	public:
		CLIViewer(model::Presentation& presentation, std::istream& is, std::ostream& os);
		void showError(const std::string& msg) override;
		void showWarning(const std::string& msg) override;
		void showInfo(const std::string& msg) override;
		std::optional<bool> askConfirmation(const std::string& msg) override;

		void showPrompt();
		void showText(const std::string& msg);
		void showWelcome();
		void resetStream();

		//CLIVisualizer& getVisualizer();
		std::istream& getIStream();
		std::ostream& getOStream();
	private:
		//CLIVisualizer m_visualizer;
		model::Presentation& m_presentation;
		std::istream& m_is;
		std::ostream& m_os;
	};
}
