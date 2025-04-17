#include "Simulation.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Model/Ant.h"
#include "../Model/Game.h"
#include "../Utils/Random.h"
#include "../View/AnthillDrawable.h"
#include "../View/Background.h"
#include "../View/UI/HUD.h"

namespace Core {

    Simulation::Simulation(const sf::Vector2u &res): resolution(res) {
        g_event_manager.set_hive_mind(&g_anthill.hive_mind);
        window = sf::RenderWindow(sf::VideoMode(resolution), title, sf::Style::Default, sf::State::Fullscreen);
        window.setVerticalSyncEnabled(true); // ограничит фпс до герцовки
        window.setIcon(sf::Image("../assets/ico.png"));
    }

    void Simulation::start_simulation() {
        g_logger.add_message("<color=#4778b3>[system]</color> Start simulation.");

        View::UI::HUD hud(resolution);
        const View::Background bg(resolution);

        // spawn anthill half the height and quarter the width
        g_anthill.drawable->set_position(
            {static_cast<float>(resolution.x) / 4.f, static_cast<float>(resolution.y) / 2.f});
        g_anthill.spawn_initial_ants(resolution);

        Game game(g_anthill);
        sf::Clock clock;
        sf::Time dt;
        float day_clock = 0;
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                } else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    const sf::Keyboard::Scancode keycode = keyPressed->scancode;
                    if (keycode == sf::Keyboard::Scancode::Escape) {
                        window.close();
                    } else if (keycode == sf::Keyboard::Scancode::Up || keycode == sf::Keyboard::Scancode::Num1) {
                        g_event_manager.generate_food(sf::Vector2f(resolution));
                    } else if (keycode == sf::Keyboard::Scancode::Down || keycode == sf::Keyboard::Scancode::Num2) {
                        g_event_manager.generate_wood(sf::Vector2f(resolution));
                    }
                } else if (const auto *mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
                    if (mouse->button == sf::Mouse::Button::Left) {
                        const sf::Vector2f pos = window.mapPixelToCoords(mouse->position);
                        for (auto it = g_anthill.ants.begin(); it != g_anthill.ants.end(); ++it) {
                            if (it->drawable->get_global_bounds().contains(pos)) {
                                it = g_anthill.ants.erase(it);
                                break;
                            }
                        }
                    }
                }
            }
            dt = clock.restart();
            day_clock += dt.asSeconds();
            // Business logic
            if (day_clock > 10) {
                g_anthill.simulate_day(resolution);
                day_clock = 0;
            }

            // Update by dt
            hud.update(dt);
            g_anthill.drawable->update(dt);
            game.update(resolution, dt);

            // Draw scene
            window.clear();
            window.draw(bg);
            window.draw(*g_anthill.drawable);
            for (const Model::Ant &ant: g_anthill.ants) window.draw(*ant.drawable);
            window.draw(*g_anthill.hive_mind.get_food_map());
            window.draw(*g_anthill.hive_mind.get_wood_map());
            for (const auto &point: g_event_manager.undetected_food) {
                window.draw(*point);
            }
            for (const auto &point: g_event_manager.undetected_wood) {
                window.draw(*point);
            }
            window.draw(hud);
            window.display();
        }
    }

}