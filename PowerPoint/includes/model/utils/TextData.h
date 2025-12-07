#pragma once

#include "model/utils/Color.h" 
#include <string>

namespace ppt::model::utils
{
    struct TextData
    {
        std::string content;
        std::string fontName = "Arial";
        float fontSize = 12.0f;
        utils::Color textColor;

        enum class HorizontalAlignment { Left, Center, Right };
        HorizontalAlignment hAlign = HorizontalAlignment::Center;

        enum class VerticalAlignment { Top, Middle, Bottom };
        VerticalAlignment vAlign = VerticalAlignment::Middle;

        TextData() : textColor(0, 0, 0, 255)
        {
        }

        TextData(const std::string& text, const std::string& font, float size, const utils::Color& color)
            : content(text), fontName(font), fontSize(size), textColor(color)
        {
        }
    };
}