#include "Background.h"

#include "../Utils/TextureManager.h"

namespace View {

    Background::Background(const sf::Vector2u& size_):
    size(size_), sprite(Utils::TextureManager::instance().get(texture_path)) {
        texture = Utils::TextureManager::instance().get(texture_path);
        texture.setRepeated(true);
        sprite.setTexture(texture);
        sprite.setTextureRect(
            sf::IntRect({0, 0}, {static_cast<int>(size.x), static_cast<int>(size.y)}));
    }

    void Background::draw(sf::RenderTarget& target, const sf::RenderStates states) const {
        target.draw(sprite, states);
    }

}
