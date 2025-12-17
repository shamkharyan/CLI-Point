#pragma once

#include "core/IViewer.h"
#include "model/Presentation.h"
#include "cli/meta/CommandRegistry.h"

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

		void showHelp(const CommandRegistry& registry);
		void showCommandHelp(const meta::CommandMeta& cmdMeta);

		//CLIVisualizer& getVisualizer();
		std::istream& getIStream();
		std::ostream& getOStream();
	private:
		void showCommandUsage(const meta::CommandMeta& cmdMeta);
		void showCommandDescription(const meta::CommandMeta& cmdMeta);
		void showArgumentsHelp(const meta::CommandMeta& cmdMeta);
	private:
		model::Presentation& m_presentation;
		std::istream& m_is;
		std::ostream& m_os;

		static constexpr std::size_t s_columnWidth = 20;
	};
}
