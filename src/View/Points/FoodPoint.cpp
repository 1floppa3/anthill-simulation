#include "FoodPoint.h"

namespace View {
    FoodPoint::FoodPoint(const sf::Vector2f& pos): Point(pos){
        this->setFillColor(sf::Color::Yellow);
    }
}