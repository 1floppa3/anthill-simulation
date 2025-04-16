#include "AntDrawable.h"

#include <cmath>
#include "AnthillDrawable.h"
#include "../Core/Simulation.h"
#include "../Utils/Random.h"
#include "../Utils/TextureManager.h"

namespace View {

    AntDrawable::AntDrawable(const sf::Vector2u& area_):
    texture(Utils::TextureManager::instance().get(texture_path)), sprite(texture), area(area_) {
        sprite.setScale({sprite_scale, sprite_scale});

        const sf::Vector2u tex_size = sprite.getTexture().getSize();
        animation.frame_size.x = static_cast<int>(tex_size.x);
        animation.frame_size.y = static_cast<int>(tex_size.y) / animation.frame_count;
        sprite.setTextureRect(sf::IntRect({0, 0}, {animation.frame_size.x, animation.frame_size.y}));
        sprite.setOrigin({static_cast<float>(animation.frame_size.x) / 2.f, static_cast<float>(animation.frame_size.y) / 2.f});

        // random pos
        float x = Utils::Random::random(static_cast<float>(area.x));
        float y = Utils::Random::random(static_cast<float>(area.y));
        sprite.setPosition({x, y});

        const sf::Angle angle = sf::degrees(Utils::Random::random(360.f));
        velocity = {std::cos(angle.asRadians()) * base_speed, std::sin(angle.asRadians()) * base_speed};
    }
    AntDrawable* AntDrawable::clone() const {
        return new AntDrawable(*this);
    }

    sf::Vector2f AntDrawable::get_position() const {
        return sprite.getPosition();
    }
    sf::FloatRect AntDrawable::get_global_bounds() const {
        return sprite.getGlobalBounds();
    }
    void AntDrawable::go_to(const sf::Vector2f& dest) {
        const sf::Vector2f pos = sprite.getPosition();

        // получаем + нормируем направляющий вектор
        sf::Vector2f dir = dest - pos;
        if (dir.length() == 0.f)
            return;
        dir = dir.normalized();

        // сбрасываем скорость к базовой при повороте
        velocity = dir * base_speed;

        // обновляем угол
        sprite.setRotation(dir.angle());
    }
    void AntDrawable::reset_speed() {
        velocity = velocity.normalized() * base_speed;
    }

    bool AntDrawable::has_reached(const sf::Vector2f &target) const {
        const float distance_squared = (get_position() - target).lengthSquared();
        return distance_squared <= reach_threshold * reach_threshold;
    }
    void AntDrawable::set_color(const sf::Color &color) {
        sprite.setColor(color);
    }

    void AntDrawable::update(const sf::Time& dt) {
        sf::Vector2f dir = velocity;
        float cur_speed = dir.length();
        if (cur_speed != 0.f)
            dir = dir.normalized();

        cur_speed += acceleration * dt.asSeconds();
        cur_speed = std::min(cur_speed, max_speed);
        velocity = dir * cur_speed;

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

        // сбрасываем скорость
        if (bounced) {
            if (velocity.length() != 0.f)
                velocity = velocity.normalized() * base_speed;
        }

        sprite.setPosition(pos);
        // зеркало по горизонтали, если муравей идет влево
        sprite.setRotation(velocity.x < 0 ? velocity.angle() + sf::degrees(180) : velocity.angle());
        sprite.setScale({velocity.x < 0 ? -sprite_scale : sprite_scale, sprite_scale});

        // анимация
        animation.elapsed_time += dt.asSeconds();
        if (animation.elapsed_time >= animation.frame_time) {
            animation.elapsed_time = 0.f;
            animation.current_frame = (animation.current_frame + 1) % animation.frame_count;
            sprite.setTextureRect(sf::IntRect(
                {0, animation.current_frame * animation.frame_size.y},
                {animation.frame_size.x, animation.frame_size.y}));
        }

        // выравенивание текста
        const sf::FloatRect sprite_bounds = sprite.getGlobalBounds();
        float desiredY = sprite.getPosition().y - sprite_bounds.size.y / 2.f - info_text.getLocalBounds().size.y - 2.f;
        if (desiredY < 0.f)
            desiredY = 0.f;

        float textX = sprite.getPosition().x - info_text.getLocalBounds().size.x / 2.f;
        if (textX < 0.f)
            textX = 0.f;
        if (textX + info_text.getLocalBounds().size.x > static_cast<float>(area.x))
            textX = static_cast<float>(area.x) - info_text.getLocalBounds().size.x;

        info_text.setPosition({ textX, desiredY });
    }
    void AntDrawable::update_text(const Model::Ant &ant) {
        info_text.update(ant);
    }

    void AntDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(info_text, states);
        target.draw(sprite, states);
    }


}