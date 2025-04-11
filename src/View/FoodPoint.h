#pragma once

#include <SFML/Graphics.hpp>

namespace View {

    class FoodPoint final : public sf::CircleShape {
        static constexpr float radius = 5.f;
    public:
        explicit FoodPoint(const sf::Vector2f &pos);
    };

}
