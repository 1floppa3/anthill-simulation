#pragma once

#include <SFML/Graphics.hpp>

class Ant final : public sf::Drawable {
    const float base_speed = 50.f;
    const float sprite_scale = 0.08f;
    const float acceleration = 200.f;
    const float max_speed = 100.f;
    const float animation_speed_multiplier = 50.f;

    const sf::Texture& texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    sf::Vector2u area;

    bool animaation_was_animated;

public:
    explicit Ant(const sf::Vector2u& size);

    void update(const sf::Time& dt);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
