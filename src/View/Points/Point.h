#ifndef ANTHILL_SIMULATION_POINT_H
#define ANTHILL_SIMULATION_POINT_H

#include "../Render/GlowedSprite.h"

namespace View {

    class Point: public Render::GlowedSprite {
    public:
        explicit Point(const sf::Vector2f &pos, const sf::Texture &texture, float sprite_scale = 1.0, const sf::Color &color = sf::Color::White);
    };
}

#endif //ANTHILL_SIMULATION_POINT_H
