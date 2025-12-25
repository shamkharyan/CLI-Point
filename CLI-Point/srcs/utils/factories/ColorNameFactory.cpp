#include "utils/factories/ColorNameFactory.h"

#include <stdexcept>

using namespace ppt::utils::fact;

const std::unordered_map<std::string, ppt::model::utils::Color> ColorNameFactory::m_colorNameMap =
{
	{"black", ppt::model::utils::Black},
	{"white", ppt::model::utils::White},
	{"red", ppt::model::utils::Red},
	{"green", ppt::model::utils::Green},
	{"blue", ppt::model::utils::Blue},
	{"yellow", ppt::model::utils::Yellow},
	{"cyan", ppt::model::utils::Cyan},
	{"magenta", ppt::model::utils::Magenta}
};

ppt::model::utils::Color ColorNameFactory::create(const std::string& rawValue)
{
	auto it = m_colorNameMap.find(rawValue);
	if (it != m_colorNameMap.end())
		return it->second;
	
	throw std::invalid_argument("Invalid color name: " + rawValue);
}