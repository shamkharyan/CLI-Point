#pragma once

#include <string>
#include <unordered_map>
#include <vector>

struct RawCommand
{
	std::string name;
	std::unordered_map<std::string, std::vector<std::string>> arguments;
};
