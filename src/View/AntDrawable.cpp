#include "AntDrawable.h"

#include <cmath>

#include "AnthillDrawable.h"
#include "../Core/Simulation.h"
#include "../Utils/Random.h"
#include "../Utils/TextureManager.h"

namespace View {

AntDrawable::AntDrawable(const sf::Vector2u& size, const sf::Font& font):
texture(Utils::TextureManager::instance().get("../assets/textures/ant.png")), sprite(texture),
animation_was_animated(false), info_text(font, "", 18) {
    area = size;
    sprite.setScale({sprite_scale, sprite_scale});
    const sf::Vector2u tex_size = sprite.getTexture().getSize();
    sprite.setOrigin({static_cast<float>(tex_size.x) / 2.f, static_cast<float>(tex_size.y) / 2.f});

    // random pos
    float x = Utils::Random::random(static_cast<float>(area.x));
    float y = Utils::Random::random(static_cast<float>(area.y));
    sprite.setPosition({x, y});

    const float angle = sf::degrees(Utils::Random::random(360.f)).asRadians();
    velocity = {std::cos(angle) * base_speed, std::sin(angle) * base_speed};

    info_text.setFillColor(sf::Color::White);
    info_text.setStyle(sf::Text::Bold);
}

sf::Vector2f AntDrawable::get_position() const {
    return sprite.getPosition();
}

void AntDrawable::update(const sf::Time& dt) {
    sf::Vector2f direction = velocity;
    float cur_speed = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (cur_speed != 0.f)
        direction /= cur_speed;

    if (Core::anthill.drawable->is_animating() && !animation_was_animated) {
        velocity = velocity / cur_speed * (base_speed * animation_speed_multiplier);
    } else if (!Core::anthill.drawable->is_animating()) {
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

    if (bounced && !animation_was_animated && !Core::anthill.drawable->is_animating()) {
        const float norm = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
        if (norm != 0.f)
            velocity = velocity / norm * base_speed;
    }

    sprite.setPosition(pos);
    const sf::Angle angle = sf::radians(std::atan2(velocity.y, velocity.x));
    sprite.setRotation(sf::degrees(angle.asDegrees()));
    animation_was_animated = Core::anthill.drawable->is_animating();
    update_info_position();
}
void AntDrawable::set_info(const std::string &info) {
    info_text.setString(info);
}

void AntDrawable::update_info_position() {
    const sf::FloatRect sprite_bounds = sprite.getGlobalBounds();
    info_text.setPosition({sprite.getPosition().x - info_text.getLocalBounds().size.x/2.f,
                         sprite.getPosition().y - sprite_bounds.size.y/2.f - static_cast<float>(info_text.getCharacterSize()) - 2.f});
}

void AntDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(info_text, states);
    states.texture = &texture;
    target.draw(sprite, states);
}

AntDrawable* AntDrawable::clone() const {
    return new AntDrawable(*this);
}

}