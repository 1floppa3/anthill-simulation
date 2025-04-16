#include "WoodPoint.h"

#include "../../Utils/TextureManager.h"

namespace View {

    WoodPoint::WoodPoint(const sf::Vector2f& pos):
    Point(pos, Utils::TextureManager::instance().get(texture_path), sprite_scale, sprite_color) {}

}
