#pragma once
#include <vector>
#include "PathCommand.h"

namespace ppt::vis
{
    class Path
    {
    public:
        void moveTo(float x, float y)
        {
            m_commands.push_back({ PathCommand::Type::MoveTo, {x,y} });
        }

        void lineTo(float x, float y)
        {
            m_commands.push_back({ PathCommand::Type::LineTo, {x,y} });
        }

        void quadTo(float cx, float cy, float x, float y)
        {
            m_commands.push_back({ PathCommand::Type::QuadTo, {x,y}, {cx,cy} });
        }

        void cubicTo(float cx1, float cy1, float cx2, float cy2, float x, float y)
        {
            m_commands.push_back({ PathCommand::Type::CubicTo, {x,y}, {cx1,cy1}, {cx2,cy2} });
        }

        void close()
        {
            m_commands.push_back({ PathCommand::Type::Close });
        }

        const std::vector<PathCommand>& commands() const { return m_commands; }

    private:
        std::vector<PathCommand> m_commands;
    };
}
