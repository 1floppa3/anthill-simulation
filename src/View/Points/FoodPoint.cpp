#include "FoodPoint.h"

#include "../../Utils/TextureManager.h"

namespace View {

    FoodPoint::FoodPoint(const sf::Vector2f& pos):
    Point(pos, Utils::TextureManager::instance().get("../assets/textures/apple.png"), sprite_scale) {

    }

}
