#include "../View/FoodPoint.h"

namespace View {

    FoodPoint::FoodPoint(const sf::Vector2f& pos): CircleShape(radius), pos(pos) {
        this->setPosition(pos);
        this->setOrigin({radius, radius});
        this->setFillColor(sf::Color::Yellow);
    }

    sf::Vector2f FoodPoint::get_pos() {
        return pos;
    }
}