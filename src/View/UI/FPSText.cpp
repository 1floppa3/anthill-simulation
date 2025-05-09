#include "FPSText.h"

#include "../../Core/Simulation.h"

namespace View::UI {

    FPSText::FPSText(): Text(Core::g_general_font, "FPS: 0", font_size), time_accumulator(0.f), frame_counter(0) {
        this->setFillColor(sf::Color::White);
        this->setPosition({margin_top_left, margin_top_left});
    }
    void FPSText::update(const sf::Time& dt) {
        time_accumulator += dt.asSeconds();
        frame_counter++;
        if (time_accumulator >= 1.f) {
            this->setString("FPS: " + std::to_string(static_cast<int>(static_cast<float>(frame_counter) / time_accumulator)));
            frame_counter = 0;
            time_accumulator = 0.f;
        }
    }

}
