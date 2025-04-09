#pragma once

#include <SFML/Graphics.hpp>

namespace View::UI {

class AnthillInfoText final : public sf::Text {
    const float margin_top_right = 32.f;
public:
    explicit AnthillInfoText(const sf::Font& font);
    void update(const sf::RenderWindow& window);
};

}