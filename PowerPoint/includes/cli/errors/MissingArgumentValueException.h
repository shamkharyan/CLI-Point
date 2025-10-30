#pragma once

#include <stdexcept>

namespace ppt::cli::err
{
	class MissingArgumentValueException : public std::runtime_error
	{
	public:
		explicit MissingArgumentValueException(const std::string& arg)
			: std::runtime_error("Missing argument values for: " + arg) {}
	};
}


