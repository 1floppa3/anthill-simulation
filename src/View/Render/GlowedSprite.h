#pragma once

#include <SFML/Graphics.hpp>

namespace View::Render {

    class GlowedSprite: public sf::Drawable, public sf::Transformable {
        const unsigned int layer_count = 3;
        const float initial_scale = 1.3f;
        const unsigned char initial_alpha = 70;

        sf::Sprite sprite;
        sf::Color glow_color;
    public:
        explicit GlowedSprite(const sf::Texture &texture, const sf::Color &color = sf::Color::White);

        sf::FloatRect get_local_bounds() const;
        sf::FloatRect get_global_bounds() const;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };

}