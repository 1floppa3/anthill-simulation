#pragma once

#define TITLE "Anthill simulation"
#define ANT_COUNT 25

#include "../Model/Anthill.h"
#include "../Utils/TextureManager.h"

namespace Core {

inline Anthill anthill;
inline sf::Texture background_texture = Utils::TextureManager::instance().get("../assets/textures/base.png");

class Simulation {
    sf::Vector2u resolution;
    sf::RenderWindow window;
    sf::Sprite background_sprite;
    sf::Font general_font;

     void load_font(const std::string& path);
public:
    explicit Simulation(const sf::Vector2u& res);

    void start_simulation();
};

}
