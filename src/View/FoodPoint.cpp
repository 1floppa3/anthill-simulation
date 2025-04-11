#include "../View/FoodPoint.h"

namespace View {

    FoodPoint::FoodPoint(const sf::Vector2f& pos): CircleShape(radius) {
        this->setPosition(pos);
        this->setOrigin({radius, radius});
        this->setFillColor(sf::Color::Yellow);
    }

}