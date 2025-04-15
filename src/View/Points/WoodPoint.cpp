#include "WoodPoint.h"

namespace View {

    View::WoodPoint::WoodPoint(const sf::Vector2f& pos): Point(pos){
        this->setFillColor(sf::Color::Red);
    }
}