#pragma once

#include <string>
#include <optional>

class IViewer
{
public:
	virtual void showError(const std::string& msg) = 0;
	virtual void showWarning(const std::string& msg) = 0;
	virtual void showInfo(const std::string& msg) = 0;
	virtual std::optional<bool> askConfirmation(const std::string& msg) = 0;
};
