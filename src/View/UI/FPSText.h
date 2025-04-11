#pragma once

#include <SFML/Graphics.hpp>

namespace View::UI {

class FPSText final : public sf::Text {
    const float margin_top_left = 16.f;
    static constexpr int font_size = 16;

    float time_accumulator;
    int frame_counter;

public:
    explicit FPSText();
    void update(const sf::Time& dt);
};

}