#include "AntInfoText.h"

#include "../../Core/Simulation.h"

namespace View::UI {

    AntInfoText::AntInfoText(): Text(Core::g_general_font, "", font_size) {
        this->setFillColor(sf::Color::White);
        this->setStyle(Bold);
    }
    void AntInfoText::update(const Model::Ant& ant) {
        const std::string info = "ID: " + std::to_string(ant.id) +
            " | " + ant.role->get_name() +
            "\nAge: " + std::to_string(ant.age) +
            " | HP: " + std::format("{:.2f}", ant.hp);
        this->setString(info);
    }

}
