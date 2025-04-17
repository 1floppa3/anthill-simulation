#include "Particle.h"

#include "../../Utils/Random.h"

namespace View::Render {

    Particle::Particle(const sf::Texture &texture, const sf::Vector2f &pos): sprite(texture),
        ttl(Utils::Random::random(1.0f, 1.5f)), lifetime(ttl), current_frame(0) {
        frame_size.x = static_cast<int>(texture.getSize().x) / frame_count;
        frame_size.y = static_cast<int>(texture.getSize().y);

        sprite.setTextureRect(sf::IntRect({0, 0}, {frame_size.x, frame_size.y}));
        sprite.setOrigin({static_cast<float>(frame_size.x)/2.f, static_cast<float>(frame_size.y)/2.f});
        sprite.setPosition(pos);
        sprite.setScale({2.f, 2.f});
    }

}
