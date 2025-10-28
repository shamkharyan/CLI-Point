#pragma once

#include <optional>
#include <string>

namespace ppt::viewer
{
	class IViewer
	{
	public:
		virtual void showError(const std::string& msg) = 0;
		virtual void showWarning(const std::string& msg) = 0;
		virtual void showInfo(const std::string& msg) = 0;
		virtual std::optional<bool> askConfirmation(const std::string& msg) = 0;
	};
}
