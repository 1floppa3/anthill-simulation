#include "../View/WoodPoint.h"

namespace View {

    View::WoodPoint::WoodPoint(const sf::Vector2f& pos): CircleShape(radius), pos(pos) {
        this->setPosition(pos);
        this->setOrigin({radius, radius});
        this->setFillColor(sf::Color::Red);
    }

    sf::Vector2f WoodPoint::get_pos() {
        return pos;
    }
}