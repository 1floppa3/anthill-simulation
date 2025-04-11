#include "Simulation.h"

#include <SFML/Graphics.hpp>

#include "../Model/Ant.h"
#include "../Utils/Random.h"
#include "../Utils/TextureManager.h"
#include "../View/AnthillDrawable.h"
#include "../View/Background.h"
#include "../View/UI/HUD.h"

namespace Core {

    Simulation::Simulation(const sf::Vector2u &res): resolution(res) {
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
                    } else if (keycode == sf::Keyboard::Scancode::Up) {
                        g_anthill.food_map->generate_food(sf::Vector2f(resolution));
                    }
                }
            }

            // Business logic
            if (!g_anthill.drawable->is_animating())
                g_anthill.simulate_day(resolution);

            // Update by dt
            sf::Time dt = clock.restart();
            hud.update(dt);
            g_anthill.drawable->update(dt);
            for (const Model::Ant &ant: g_anthill.ants) {
                if (ant.is_alive()) {
                    ant.do_work(*g_anthill.food_map);
                    ant.drawable->update_text(ant);
                    ant.drawable->update(dt);
                }
            }

            // Draw scene
            window.clear();
            window.draw(bg);
            window.draw(*g_anthill.drawable);
            for (const Model::Ant &ant: g_anthill.ants) window.draw(*ant.drawable);
            window.draw(*g_anthill.food_map);
            window.draw(hud);
            window.display();
        }
    }

}