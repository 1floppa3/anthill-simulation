#pragma once

#include <SFML/Graphics.hpp>
#include "Point.h"

namespace View {
    class WoodPoint final : public Point {
        static constexpr float sprite_scale = .3f;
    public:
        explicit WoodPoint(const sf::Vector2f &pos);
    };
}
