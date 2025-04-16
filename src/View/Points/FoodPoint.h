#pragma once

#include <SFML/Graphics.hpp>
#include "Point.h"

namespace View {

    class FoodPoint final : public Point {
        static constexpr const char* texture_paths[3] = {
            "../assets/textures/apple_red.png",
            "../assets/textures/apple_gold.png",
            "../assets/textures/apple_green.png"
        };
        static constexpr float sprite_scale = 1.5f;
        static constexpr sf::Color sprite_color = {255, 215, 0};
    public:
        explicit FoodPoint(const sf::Vector2f &pos);
    };
}
