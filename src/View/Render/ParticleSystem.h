#pragma once

#include <SFML/Graphics.hpp>

#include "Particle.h"
#include "../../Utils/TextureManager.h"

namespace View::Render {

    class ParticleSystem final : public sf::Drawable {
        const std::string texture_path = "../assets/textures/dust_particle.png";
        const unsigned particles_count = 1;

        std::vector<Particle> particles;
    public:
        void spawn_dust(const sf::Vector2f& pos);
        void update(sf::Time dt);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    };

}
