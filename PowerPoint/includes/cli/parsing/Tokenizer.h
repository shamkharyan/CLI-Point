#pragma once

#include <istream>

namespace ppt::cli
{
	struct Token
	{
		enum class Type { String, Word, Comma, EOL, Error };
		Type type;
		std::string value;
	};

	class Tokenizer
	{
	public:
		Tokenizer(std::istream& is);

		Token getNextToken();

		void reset() noexcept;
		bool isError() const noexcept;
		bool isEOL() const noexcept;
	private:
		Token getStringToken();
		Token getToken();
		Token errorReturn() noexcept;
		Token eolReturn() noexcept;
	private:
		std::istream& m_is;
		bool m_error;
		bool m_eol;
	};
}
