#pragma once

#include <SFML/Graphics.hpp>
#include "Point.h"

namespace View {
    class WoodPoint final : public Point {
        static constexpr const char  *texture_path = "../assets/textures/log.png";
        static constexpr float sprite_scale = .4f;
        static constexpr sf::Color sprite_color = {139, 69, 19};
    public:
        explicit WoodPoint(const sf::Vector2f &pos);
    };
}
