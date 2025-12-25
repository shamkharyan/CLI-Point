#pragma once
#include <vector>
#include "PathCommand.h"

namespace ppt::vis
{
    class Path
    {
    public:
        using container = std::vector<PathCommand>;
        using iterator = container::iterator;
        using const_iterator = container::const_iterator;

    public:
        void moveTo(float x, float y);
        void lineTo(float x, float y);
        void quadTo(float cx, float cy, float x, float y);
        void cubicTo(float cx1, float cy1, float cx2, float cy2, float x, float y);
        void close();

        iterator begin() noexcept { return m_commands.begin(); }
        iterator end() noexcept { return m_commands.end(); }

        const_iterator begin() const noexcept { return m_commands.begin(); }
        const_iterator end() const noexcept { return m_commands.end(); }

        const_iterator cbegin() const noexcept { return m_commands.cbegin(); }
        const_iterator cend() const noexcept { return m_commands.cend(); }

    private:
        container m_commands;
    };
}
