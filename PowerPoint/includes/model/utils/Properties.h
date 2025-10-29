#pragma once

#include "Color.h"

#include <string>

namespace ppt::model::utils
{
  struct Properties
  {
    Color backgroundColor;
    Color outlineColor;
    std::size_t outlineThinkness;
    std::string text;
    Color textColor;
    std::string textFont;
    std::string textStyle;
  };
}