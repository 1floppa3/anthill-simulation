#include "Point.h"
#include "FoodPoint.h"

namespace View {

    Point::Point(const sf::Vector2f& pos): CircleShape(radius), pos(pos) {
        this->setPosition(pos);
        this->setOrigin({radius, radius});
        this->setFillColor(sf::Color::White);
    }

    sf::Vector2f Point::get_pos() {
        return pos;
    }
}