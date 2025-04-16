#include "Simulation.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Model/Ant.h"
#include "../Model/Enemy.h"
#include "../Utils/Random.h"
#include "../Utils/TextureManager.h"
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
        View::UI::HUD hud(resolution);
        const View::Background bg(resolution, "../assets/textures/base.png");

        g_logger.add_message("[system] Start simulation");

        // spawn anthill half the height and quarter the width
        g_anthill.drawable->set_position(
            {static_cast<float>(resolution.x) / 4.f, static_cast<float>(resolution.y) / 2.f});

        sf::Clock clock;
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
                    }else if (keycode == sf::Keyboard::Scancode::E || keycode == sf::Keyboard::Scancode::Num3) {
                        g_event_manager.generate_enemy(resolution);
                    }
                }
            }

            // Business logic
            if (!g_anthill.drawable->is_animating()){
                g_anthill.simulate_day(resolution);
            }

            // Update by dt
            sf::Time dt = clock.restart();
            hud.update(dt);
            g_anthill.drawable->update(dt);
            for (const Model::Ant &ant: g_anthill.ants) {
                if (ant.is_alive()) {
                    ant.detect_objects(g_event_manager);
                    ant.do_work(g_anthill.hive_mind);
                    ant.drawable->update_text(ant);
                    ant.drawable->update(dt);
                }
            }
            // enemies
            for (auto it = g_event_manager.undetected_enemies.begin(); it !=  g_event_manager.undetected_enemies.end(); ++it) {
                if(!(*it)->is_fighting)
                    (*it)->drawable->update(dt);
            }

            // Draw scene
            window.clear();
            window.draw(bg);
            window.draw(*g_anthill.drawable);
            for (const Model::Ant &ant: g_anthill.ants) window.draw(*ant.drawable);
            window.draw(*g_anthill.hive_mind.get_food_map());
            window.draw(*g_anthill.hive_mind.get_wood_map());

            g_anthill.hive_mind.get_enemy_map()->update_enemies(dt);
            window.draw(*g_anthill.hive_mind.get_enemy_map());
            for (auto it = g_event_manager.undetected_food.begin(); it !=  g_event_manager.undetected_food.end(); ++it) {
                window.draw(**it);
            }
            for (auto it = g_event_manager.undetected_wood.begin(); it !=  g_event_manager.undetected_wood.end(); ++it) {
                window.draw(**it);
            }
            // enemies
            for (auto it = g_event_manager.undetected_enemies.begin(); it !=  g_event_manager.undetected_enemies.end(); ++it) {
                window.draw(*(*it)->drawable);
            }

            window.draw(hud);
            window.display();
        }
    }

}