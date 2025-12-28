#include "cli/parsing/Tokenizer.h"

#include <iostream>

using namespace ppt::cli;

Tokenizer::Tokenizer(std::istream& is)
    : m_is(is), m_error(false), m_eol(false)
{
}

bool Tokenizer::isError() const noexcept { return m_error; }
bool Tokenizer::isEOL() const noexcept { return m_eol; }
void Tokenizer::reset() noexcept { m_error = false; m_eol = false; }

Token Tokenizer::getNextToken()
{
    if (isError()) return { Token::Type::Error, "" };
    if (isEOL())  return { Token::Type::EOL, "\n" };

    char c;

    while (true)
    {
        if (!m_is.get(c))
        {
            if (m_is.eof())
                return eolReturn();
            return errorReturn();
        }

        if (c == '\n')
            return eolReturn();

        if (c == '#')
        {
            while (m_is.get(c) && c != '\n');
            if (c == '\n' || m_is.eof())
                return eolReturn();
            return errorReturn();
        }

        if (!std::isspace(static_cast<unsigned char>(c)))
            break;
    }

    if (c == '"') return getStringToken();
    if (c == ',') return { Token::Type::Comma, "," };

    m_is.unget();
    return getToken();
}

Token Tokenizer::getStringToken()
{
    char c;
    std::string token;
    bool closed = false;

    while (true)
    {
        if (!m_is.get(c))
        {
            if (m_is.eof()) break;
            return errorReturn();
        }

        if (c == '\\' && m_is.peek() == '"')
        {
            m_is.get(c);
            token.push_back(c);
            continue;
        }

        if (c == '"')
        {
            closed = true;
            break;
        }

        if (c == '\n')
        {
            m_is.unget();
            break;
        }

        token.push_back(c);
    }

    if (!closed) return errorReturn();

    int next = m_is.peek();
    if (next != EOF && next != ',' && !std::isspace(next) && next != '\n')
        return errorReturn();

    return { Token::Type::String, token };
}

Token Tokenizer::getToken()
{
    char c;
    std::string token;

    while (true)
    {
        if (!m_is.get(c))
        {
            if (m_is.eof()) break;
            return errorReturn();
        }

        if (c == '#')
        {
            while (m_is.get(c) && c != '\n');
            if (c == '\n')
            {
                m_is.unget();
                return { Token::Type::Word, token };
            }
            if (m_is.eof())
                return eolReturn();
            return errorReturn();
        }

        if (c == ',' || c == '\n' || std::isspace(static_cast<unsigned char>(c)))
        {
            if (c == ',' || c == '\n')
                m_is.unget();
            break;
        }

        if (!std::isalnum(static_cast<unsigned char>(c)) && c != '_' && c != '-' && c != '.')
            return errorReturn();

        token.push_back(c);
    }

    if (token.empty()) return eolReturn();

    return { Token::Type::Word, token };
}

Token Tokenizer::errorReturn() noexcept
{
    m_error = true;
    return { Token::Type::Error, "" };
}

Token Tokenizer::eolReturn() noexcept
{
    m_eol = true;
    return { Token::Type::EOL, "\n" };
}