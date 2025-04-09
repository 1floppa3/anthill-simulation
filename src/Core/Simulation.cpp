#include "Simulation.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Model/Ant.h"
#include "../Utils/Random.h"
#include "../Utils/TextureManager.h"
#include "../View/AnthillDrawable.h"
#include "../View/UI/HUD.h"

namespace Core {

void Simulation::load_font(const std::string& path) {
    if (!general_font.openFromFile(path))
        throw std::runtime_error("Error: Unable to load font from file: " + path);
}

Simulation::Simulation(const sf::Vector2u& res):
resolution(res), background_sprite(background_texture) {
    window = sf::RenderWindow(sf::VideoMode(resolution), TITLE, sf::Style::Default, sf::State::Windowed);

    // Background
    background_texture.setRepeated(true);
    background_sprite.setTextureRect(sf::IntRect({0, 0},
        {static_cast<int>(resolution.x), static_cast<int>(resolution.y)}));

    // Spawn anthill drawable object
    anthill.drawable->set_position(
        {static_cast<float>(resolution.x) / 4.f, static_cast<float>(resolution.y) / 2.f});

    load_font("../assets/fonts/Jura-VariableFont_wght.ttf");
}

void Simulation::start_simulation() {
    View::UI::HUD hud(window, general_font);

    sf::Clock clock;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                const sf::Keyboard::Scancode keycode = keyPressed->scancode;
                if (keycode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                } else if (keycode == sf::Keyboard::Scancode::Right || keycode == sf::Keyboard::Scancode::D) {
                    if (!anthill.drawable->is_animating()) {
                        anthill.drawable->expand();
                        ++anthill.day_counter;
                        anthill.ants.emplace_back(0, Utils::Random::random(10, 40), resolution, general_font);
                        for (Ant& ant : anthill.ants) {
                            if (ant.is_alive()) {
                                --ant.health;
                                ++ant.age;
                            }
                        }
                    }
                }
            }
        }

        sf::Time dt = clock.restart();

        hud.update(dt);
        anthill.drawable->update(dt);
        for (const Ant& ant : anthill.ants) {
            if (ant.is_alive()) {
                std::string info = "Age: " + std::to_string(ant.age) +
                                   " HP: " + std::to_string(ant.health) +
                                   " " + ant.role->get_name();
                ant.drawable->set_info(info);
                ant.drawable->set_info(info);
                ant.drawable->update(dt);
            }
        }


        window.clear();
        window.draw(background_sprite);
        window.draw(*anthill.drawable);
        for (const Ant& ant : anthill.ants) if (ant.is_alive()) window.draw(*ant.drawable);
        window.draw(hud);
        window.display();
    }
}

}
