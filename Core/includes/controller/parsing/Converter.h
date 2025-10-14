#pragma once

#include <string>

class Converter
{
public:
	static std::size_t stringToPosNumer(const std::string& str);
private:
	Converter() = delete;
};
