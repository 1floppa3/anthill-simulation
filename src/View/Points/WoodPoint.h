#pragma once

#include <SFML/Graphics.hpp>
#include "Point.h"

namespace View {
    class WoodPoint final : public Point {
    public:
        explicit WoodPoint(const sf::Vector2f &pos);
    };
}
