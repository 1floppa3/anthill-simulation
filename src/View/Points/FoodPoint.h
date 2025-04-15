#pragma once

#include <SFML/Graphics.hpp>
#include "Point.h"

namespace View {

    class FoodPoint final : public Point {
    public:
        explicit FoodPoint(const sf::Vector2f &pos);
    };
}
