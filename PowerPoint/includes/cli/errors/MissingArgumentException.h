#pragma once

#include <stdexcept>

namespace ppt::cli::err
{
	class MissingArgumentException : public std::runtime_error
	{
	public:
		explicit MissingArgumentException(const std::string& arg)
			: std::runtime_error("Missing argument: " + arg) {}
	};
}

