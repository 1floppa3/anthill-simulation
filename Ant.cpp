#include "Ant.h"

#include <cmath>

#include "Anthill.h"
#include "TextureManager.h"

Ant::Ant(const sf::Vector2u& size):
    texture(TextureManager::instance().get("../assets/textures/ant.png")),
    sprite(texture),
    animaation_was_animated(false)
{
    area = size;
    sprite.setScale({sprite_scale, sprite_scale});
    const sf::Vector2u tex_size = sprite.getTexture().getSize();
    sprite.setOrigin({static_cast<float>(tex_size.x) / 2.f, static_cast<float>(tex_size.y) / 2.f});

    // random pos
    auto x = static_cast<float>(std::rand() % area.x);
    auto y = static_cast<float>(std::rand() % area.y);
    sprite.setPosition({x, y});

    const float angle = sf::degrees(static_cast<float>(std::rand() % 360)).asRadians();
    velocity = {std::cos(angle) * base_speed, std::sin(angle) * base_speed};
}

void Ant::update(const sf::Time& dt) {
    sf::Vector2f direction = velocity;
    float cur_speed = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (cur_speed != 0.f)
        direction /= cur_speed;

    if (Anthill::instance().is_animating && !animaation_was_animated) {
        velocity = velocity / cur_speed * (base_speed * animation_speed_multiplier);
    } else if (!Anthill::instance().is_animating) {
        cur_speed += acceleration * dt.asSeconds();
        cur_speed = std::min(cur_speed, max_speed);
        velocity = direction * cur_speed;
    }

    sf::Vector2f pos = sprite.getPosition();
    pos += velocity * dt.asSeconds();

    const sf::FloatRect bounds = sprite.getGlobalBounds();
    const float half_width = bounds.size.x / 2.f;
    const float half_height = bounds.size.y / 2.f;

    bool bounced = false;
    if (pos.x - half_width < 0.f) {
        pos.x = half_width;
        velocity.x = -velocity.x;
        bounced = true;
    } else if (pos.x + half_width > static_cast<float>(area.x)) {
        pos.x = static_cast<float>(area.x) - half_width;
        velocity.x = -velocity.x;
        bounced = true;
    }
    if (pos.y - half_height < 0.f) {
        pos.y = half_height;
        velocity.y = -velocity.y;
        bounced = true;
    } else if (pos.y + half_height > static_cast<float>(area.y)) {
        pos.y = static_cast<float>(area.y) - half_height;
        velocity.y = -velocity.y;
        bounced = true;
    }

    if (bounced && !animaation_was_animated && !Anthill::instance().is_animating) {
        const float norm = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
        if (norm != 0.f)
            velocity = velocity / norm * base_speed;
    }

    sprite.setPosition(pos);
    const sf::Angle angle = sf::radians(std::atan2(velocity.y, velocity.x));
    sprite.setRotation(sf::degrees(angle.asDegrees()));
    animaation_was_animated = Anthill::instance().is_animating;
}

void Ant::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.texture = &texture;
    target.draw(sprite, states);
}
