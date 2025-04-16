#include "GlowedSprite.h"

namespace View::Render {

    GlowedSprite::GlowedSprite(const sf::Texture &texture, const sf::Color &color): sprite(texture), glow_color(color) {
        const sf::Vector2u tex_size = sprite.getTexture().getSize();
        sprite.setOrigin({static_cast<float>(tex_size.x) / 2.f, static_cast<float>(tex_size.y) / 2.f});
    }

    sf::FloatRect GlowedSprite::get_local_bounds() const {
        return sprite.getLocalBounds();
    }

    sf::FloatRect GlowedSprite::get_global_bounds() const {
        return sprite.getGlobalBounds();
    }

    void GlowedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();

        sf::Sprite glow_sprite = sprite;
        sf::RenderStates glow_states = states;
        glow_states.blendMode = sf::BlendAdd;
        sf::Color color = glow_color;
        color.a = initial_alpha;
        float scale_factor = initial_scale;

        for (int i = 0; i < layer_count; ++i) {
            glow_sprite.setColor(color);
            glow_sprite.setScale({sprite.getScale().x * scale_factor, sprite.getScale().y * scale_factor});
            target.draw(glow_sprite, glow_states);
            color.a -= initial_alpha / layer_count;
            scale_factor -= (initial_scale - 0.9f) / static_cast<float>(layer_count);
        }

        glow_sprite.setColor(sf::Color(glow_color.r, glow_color.g, glow_color.b, 80));
        glow_sprite.setScale({sprite.getScale().x * 1.6f, sprite.getScale().y * 1.6f});
        target.draw(glow_sprite, glow_states);

        target.draw(sprite, states);
    }

}