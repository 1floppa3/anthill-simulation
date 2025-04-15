#ifndef ANTHILL_SIMULATION_POINT_H
#define ANTHILL_SIMULATION_POINT_H

#include "SFML/Graphics/Sprite.hpp"

namespace View {

    class Point: public sf::Sprite {
    public:
        explicit Point(const sf::Vector2f &pos, const sf::Texture &texture, float sprite_scale = 1.0);
    };
}

#endif //ANTHILL_SIMULATION_POINT_H
