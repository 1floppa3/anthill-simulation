#pragma once

#include <SFML/Graphics.hpp>

class AnthillInfoText final : public sf::Text {
    const float margin = 32.f;
public:
    explicit AnthillInfoText(const sf::Font& font);
    void update(const sf::RenderWindow& window);
};
