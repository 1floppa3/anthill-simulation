#pragma once

#include <SFML/Graphics.hpp>
#include "Point.h"

namespace View {

    class FoodPoint final : public Point {
        static constexpr float sprite_scale = .3f;
    public:
        explicit FoodPoint(const sf::Vector2f &pos);
    };
}
