#pragma once

#include "model/utils/Color.h"
#include <optional>

namespace ppt::vis
{
    struct Brush
    {
        std::optional<model::utils::Color> fillColor;
    };
}
