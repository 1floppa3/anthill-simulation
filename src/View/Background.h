#pragma once

#include <SFML/Graphics.hpp>

namespace View {

    class Background final : public sf::Drawable {
        const std::string texture_path = "../assets/textures/base.png";
        sf::Texture texture;
        sf::Vector2u size;
        sf::Sprite sprite;

    public:
        Background(const sf::Vector2u &size_);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };

}
