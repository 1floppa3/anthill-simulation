#include "Point.h"
#include "../../Utils/TextureManager.h"

namespace View {

    Point::Point(const sf::Vector2f& pos, const sf::Texture &texture, const float sprite_scale): Sprite(texture) {
        this->setPosition(pos);
        this->setScale({sprite_scale, sprite_scale});
        const sf::Vector2u tex_size = this->getTexture().getSize();
        this->setOrigin({static_cast<float>(tex_size.x) / 2.f, static_cast<float>(tex_size.y) / 2.f});
    }

}
