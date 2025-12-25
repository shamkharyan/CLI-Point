#pragma once

#include "model/utils/Color.h" 
#include <string>

namespace ppt::model::utils
{
    struct TextStyle
    {
        std::string fontName = "Arial";
        float fontSize = 12.0f;
        utils::Color fontColor;
    };
}