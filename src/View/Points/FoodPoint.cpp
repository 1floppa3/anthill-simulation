#include "FoodPoint.h"

#include "../../Utils/Random.h"
#include "../../Utils/TextureManager.h"

namespace View {

    FoodPoint::FoodPoint(const sf::Vector2f& pos):
    Point(pos, Utils::TextureManager::instance().get(Utils::Random::random_element(texture_paths)),
        sprite_scale, sprite_color) {}

}
