#ifndef ANTHILL_SIMULATION_POINT_H
#define ANTHILL_SIMULATION_POINT_H

#include <SFML/Graphics/CircleShape.hpp>

namespace View {

    class Point: public sf::CircleShape {
        static constexpr float radius = 5.f;
        const sf::Vector2f pos;
    public:
        explicit Point(const sf::Vector2f &pos);
        sf::Vector2f get_pos();
    };
}

#endif //ANTHILL_SIMULATION_POINT_H
