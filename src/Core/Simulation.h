#pragma once

#define TITLE "Anthill simulation"
#define ANT_COUNT 25

#include "../Model/Anthill.h"
#include "../Utils/TextureManager.h"
#include "EventManager.h"

namespace Core {

    inline Anthill anthill;
    inline sf::Texture background_texture = Utils::TextureManager::instance().get("../assets/textures/base.png");

    class Simulation {
        sf::Vector2u resolution;
        sf::RenderWindow window;
        sf::Time dt;
        sf::Sprite background_sprite;
        sf::Font general_font;
        EventManager event_manager;

        void load_font(const std::string &path);

        void update_ants_info();
        void draw_ants();
        void draw_food();
    public:
        explicit Simulation(const sf::Vector2u &res);

        void start_simulation();
    };

}
