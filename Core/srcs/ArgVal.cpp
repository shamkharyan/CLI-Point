//#include "ArgVal.h"
//
//#include <variant>
//#include <string>
//
//ArgVal::ArgVal() : m_value(std::monostate{}) {}
//ArgVal::ArgVal(std::size_t n) : m_value(n) {}
//ArgVal::ArgVal(std::string str) : m_value(str) {}
//ArgVal::ArgVal(Coord c) : m_value(c) {}
//ArgVal::ArgVal(Color c) : m_value(c) {}
//ArgVal::ArgVal(std::size_t x, std::size_t y) : m_value(Coord(x, y)) {}
//ArgVal::ArgVal(std::size_t r, std::size_t g, std::size_t b) : m_value(Color(r, g, b)) {}
//
//bool ArgVal::isNumber() const noexcept { return std::holds_alternative<std::size_t>(m_value); }
//bool ArgVal::isString() const noexcept { return std::holds_alternative<std::string>(m_value); }
//bool ArgVal::isCoord() const noexcept { return std::holds_alternative<Coord>(m_value); }
//bool ArgVal::isColor() const noexcept { return std::holds_alternative<Color>(m_value); }
//bool ArgVal::isNone() const noexcept { return std::holds_alternative<std::monostate>(m_value); }
//
//ArgVal::Type ArgVal::getType() const noexcept
//{
//	if (isNumber())
//		return Type::NUMBER;
//	else if (isString())
//		return Type::STRING;
//	else if (isCoord())
//		return Type::COORD;
//	else if (isColor())
//		return Type::COLOR;
//	return Type::NONE;
//}
//
//std::size_t ArgVal::asNumber() { return std::get<std::size_t>(m_value); }
//std::string ArgVal::asString() { return std::get<std::string>(m_value); }
//ArgVal::Coord ArgVal::asCoord() { return std::get<Coord>(m_value); }
//ArgVal::Color ArgVal::asColor() { return std::get<Color>(m_value); }