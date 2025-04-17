#include "ParticleSystem.h"

namespace View::Render {

    void ParticleSystem::spawn_dust(const sf::Vector2f &pos) {
        const sf::Texture &texture = Utils::TextureManager::instance().get(texture_path);
        particles.emplace_back(texture, pos);
    }
    void ParticleSystem::update(const sf::Time dt) {
        const float dt_sec = dt.asSeconds();
        for (auto it = particles.begin(); it != particles.end();) {
            it->ttl -= dt_sec;
            if (it->ttl <= 0.f) {
                it = particles.erase(it);
                continue;
            }

            const float progress = 1.f - (it->ttl / it->lifetime);

            const int frame = std::min<int>(
                Particle::frame_count - 1,
                static_cast<int>(progress * Particle::frame_count)
            );
            if (frame != it->current_frame) {
                it->current_frame = frame;
                it->sprite.setTextureRect(sf::IntRect(
                    {frame * it->frame_size.x, 0},
                    {it->frame_size.x, it->frame_size.y}
                    ));
            }
            sf::Color c = it->sprite.getColor();
            c.a = static_cast<unsigned char>(255 * (1.f - progress));
            it->sprite.setColor(c);

            ++it;
        }
    }

    void ParticleSystem::draw(sf::RenderTarget &target, const sf::RenderStates states) const {
        for (const auto& p : particles)
            target.draw(p.sprite, states);
    }

}