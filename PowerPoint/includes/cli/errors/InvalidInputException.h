#pragma once

#include <stdexcept>

namespace ppt::cli::err
{
	class InvalidInputException : public std::runtime_error
	{
	public:
		explicit InvalidInputException(const std::string& input)
			: std::runtime_error("Invalid input: " + input) {}
	};
}