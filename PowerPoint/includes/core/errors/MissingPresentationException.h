#pragma once

#include <stdexcept>

namespace ppt::core::err
{
	class MissingPresentationException : public std::runtime_error
	{
	public:
		explicit MissingPresentationException()
			: std::runtime_error("Presentation don't exist") {}
	};
}
