#pragma once

#include <SFML/Graphics.hpp>

namespace View::Render {

    struct Particle {
        sf::Sprite sprite;
        float ttl;
        float lifetime;
        int current_frame;
        static constexpr int frame_count = 4;
        sf::Vector2i frame_size;

        explicit Particle(const sf::Texture& texture, const sf::Vector2f& pos);
    };

}
