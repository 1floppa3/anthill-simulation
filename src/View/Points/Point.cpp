#include "Point.h"
#include "../../Utils/TextureManager.h"

namespace View {

    Point::Point(const sf::Vector2f& pos, const sf::Texture &texture, const float sprite_scale, const sf::Color &color): GlowedSprite(texture, color) {
        this->setPosition(pos);
        this->setScale({sprite_scale, sprite_scale});
    }

}
