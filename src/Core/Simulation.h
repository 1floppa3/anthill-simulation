#pragma once

#include "../Model/Anthill.h"
#include "../Utils/TextureManager.h"
#include "../View/UI/Logger.h"
#include "EventManager.h"

namespace Core {

    inline View::UI::Logger g_logger;
    inline Model::Anthill g_anthill;
    inline Core::EventManager g_event_manager;

    inline auto g_general_font = sf::Font("../assets/fonts/Jura-VariableFont_wght.ttf");
    inline auto g_log_font = sf::Font("../assets/fonts/JetBrainsMono-VariableFont_wght.ttf");

    class Simulation {
        const std::string title = "Anthill simulation";

        sf::Vector2u resolution;
        sf::RenderWindow window;

    public:
        explicit Simulation(const sf::Vector2u &res);
        void start_simulation();
    };

}
