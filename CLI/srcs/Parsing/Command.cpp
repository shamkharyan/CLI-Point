//#include "Command.h"
//#include "ArgVal.h"
//
//#include <string>
//#include <stdexcept>
//
//Command::Command(const std::string& name) : m_name(name) {}
//
//bool Command::operator==(const Command& other) const noexcept
//{
//	return m_name == other.m_name;
//}
//
//bool Command::operator!=(const Command& other) const noexcept
//{
//	return m_name != other.m_name;
//}
//
//void Command::setName(const std::string& name)
//{
//	m_name = name;
//}
//
//const std::string& Command::getName() const
//{
//	return m_name;
//}
//
//void Command::addArg(const std::string& argName, ArgVal::Type t, bool required)
//{
//	m_args[argName] = { required, t };
//}
//
//void Command::removeArg(const std::string& argName)
//{
//	m_args.erase(argName);
//}
//
//void Command::setArgValue(const std::string& argName, ArgVal argVal)
//{
//	if (m_args.find(argName) == m_args.end())
//		throw std::runtime_error("Wrong argument name");
//	if (m_args[argName].type != argVal.getType())
//		throw std::runtime_error("Wrong argument type");
//	m_args[argName].value = argVal;
//}
//
//bool Command::findArg(const std::string& argName) const
//{
//	return m_args.find(argName) != m_args.end();
//}
//
