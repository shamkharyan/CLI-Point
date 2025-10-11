//#pragma once
//
//#include <variant>
//#include <string>
//
//class ArgVal
//{
//public:
//	enum class Type
//	{
//		NUMBER,
//		STRING,
//		COORD,
//		COLOR,
//		NONE
//	};
//
//	struct Coord
//	{
//		std::size_t x;
//		std::size_t y;
//
//		Coord(std::size_t x, std::size_t y) : x(x), y(y) {}
//	};
//
//	struct Color
//	{
//		std::size_t r;
//		std::size_t g;
//		std::size_t b;
//
//		Color(std::size_t r, std::size_t g, std::size_t b) : r(r), g(g), b(b) {}
//	};
//
//public:
//	ArgVal();
//	ArgVal(std::size_t n);
//	ArgVal(std::string str);
//	ArgVal(Coord c);
//	ArgVal(Color c);
//	ArgVal(std::size_t x, std::size_t y);
//	ArgVal(std::size_t r, std::size_t g, std::size_t b);
//
//	bool isNumber() const noexcept;
//	bool isString() const noexcept;
//	bool isCoord() const noexcept;
//	bool isColor() const noexcept;
//	bool isNone() const noexcept;
//
//	Type getType() const noexcept;
//
//	std::size_t asNumber();
//	std::string asString();
//	Coord asCoord();
//	Color asColor();
//private:
//	std::variant<std::size_t, std::string, Coord, Color, std::monostate> m_value;
//};
