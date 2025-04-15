#pragma once

#include <SFML/Graphics.hpp>

namespace View {

    class WoodPoint final : public sf::CircleShape {
        static constexpr float radius = 5.f;
        const sf::Vector2f pos;
    public:
        explicit WoodPoint(const sf::Vector2f &pos);
        sf::Vector2f get_pos();
    };

}
