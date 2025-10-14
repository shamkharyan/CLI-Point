#include "controller/parsing/Converter.h"
#include <stdexcept>

std::size_t Converter::stringToPosNumer(const std::string& str)
{
	std::size_t num = 0;

	for (char c : str)
	{
		if (!std::isdigit(c))
			throw std::runtime_error("Can't convert to positive number");
		num = num * 10 + c - '0';
	}
	return num;
}