#pragma once

#include <SFML/Graphics.hpp>

#include "AnthillInfoText.h"
#include "FPSText.h"

namespace View::UI {

    class HUD final : public sf::Drawable {
        sf::Vector2u window_size;

        AnthillInfoText anthill_info_text;
        FPSText fps_text;

    public:
        explicit HUD(const sf::Vector2u& size);
        void update(const sf::Time& dt);
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    };

}
