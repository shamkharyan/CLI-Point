#pragma once

#include <string>
#include <vector>

class ArgValueTypeChecker
{
public:

	static bool checkType(
		const enum class ArgValueType type,
		const std::vector<std::string>& values);

	static bool isString(const std::vector<std::string>& values);
	static bool isPath(const std::vector<std::string>& values);
	static bool isInteger(const std::vector<std::string>& values);
	static bool isFloat(const std::vector<std::string>& values);
	static bool isBoolean(const std::vector<std::string>& values);
	static bool isColor(const std::vector<std::string>& values);
	static bool isRGB(const std::vector<std::string>& values);
	static bool isRGBA(const std::vector<std::string>& values);
	static bool isShape(const std::vector<std::string>& values);
};
