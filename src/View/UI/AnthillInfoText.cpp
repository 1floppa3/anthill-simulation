#include "AnthillInfoText.h"

#include "../AnthillDrawable.h"
#include "../../Core/Simulation.h"

namespace View::UI {

AnthillInfoText::AnthillInfoText(const sf::Font &font): Text(font, "", 36) {
    this->setFillColor(sf::Color::White);
}

void AnthillInfoText::update(const sf::RenderWindow &window) {
    int population = 0;
    for (Ant& ant : Core::anthill.ants) if (ant.is_alive()) ++population;
    this->setString("Days expired: " + std::to_string(Core::anthill.day_counter) + '\n'
        + "Population: " + std::to_string(population) + '\n');
    this->setPosition({static_cast<float>(window.getSize().x) - this->getLocalBounds().size.x - margin_top_right, margin_top_right});
}

}
