#pragma once

#include <SFML/Graphics.hpp>

#include "AnthillInfoText.h"
#include "FPSText.h"

namespace View::UI {

class HUD final : public sf::Drawable {
    const sf::RenderWindow* window;

    AnthillInfoText anthill_info_text;
    FPSText fps_text;

public:
    HUD(const sf::RenderWindow& w, const sf::Font& f);

    void update(const sf::Time& dt);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

}
