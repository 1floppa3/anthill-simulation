#include "AnthillInfoText.h"

#include "../AnthillDrawable.h"
#include "../../Core/Simulation.h"

namespace View::UI {

    AnthillInfoText::AnthillInfoText(): Text(Core::g_general_font, "", font_size) {
        this->setFillColor(sf::Color::White);
    }
    void AnthillInfoText::update(const sf::Vector2u &window_size) {
        int population = 0;
        for (Model::Ant& ant : Core::g_anthill.ants) if (ant.is_alive()) ++population;

        this->setString("Days expired: " + std::to_string(Core::g_anthill.day_counter) + "\n" +
            "Anthill population: " + std::to_string(population) + '\n' +
            "Anthill area: " + std::format("{:.2f}", Core::g_anthill.drawable->get_area()/10000.f) + '\n' +
            "Food: " + std::to_string(Core::g_anthill.get_food_count()) + '\n' +
            "Wood: " + std::to_string(Core::g_anthill.get_wood_count()));
        this->setPosition({static_cast<float>(window_size.x) - this->getLocalBounds().size.x - margin_top_right, margin_top_right});
    }

}
