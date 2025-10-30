#pragma once

#include <stdexcept>

namespace ppt::core::err
{
	class EmptyPresentationException : public std::runtime_error
	{
	public:
		explicit EmptyPresentationException()
			: std::runtime_error("Presentation is empty") {}
	};
}
