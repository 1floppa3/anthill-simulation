#pragma once

#include <SFML/Graphics.hpp>

namespace View::UI {

    class AnthillInfoText final : public sf::Text {
        const float margin_top_right = 32.f;
        static constexpr int font_size = 32;

    public:
        explicit AnthillInfoText();
        void update(const sf::Vector2u& window_size);
    };

}