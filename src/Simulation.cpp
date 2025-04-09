#include <iostream>
#include "Simulation.h"
#include "Drawable/AnthillDrawable.h"
#include "TextureManager.h"
#include "Drawable/AnthillInfoText.h"

void Simulation::start_simulation() {
    std::srand(time(nullptr));

    auto window = sf::RenderWindow(sf::VideoMode::getDesktopMode(), TITLE, sf::Style::Default, sf::State::Windowed);

    sf::Vector2u size = window.getSize();

    AnthillDrawable::instance().set_position({static_cast<float>(size.x) / 4.f, static_cast<float>(size.y) / 2.f});

    sf::Texture texture = TextureManager::instance().get("../assets/textures/base.png");
    texture.setRepeated(true);
    sf::Sprite background_sprite(texture, sf::IntRect({0, 0},
                                                      {static_cast<int>(size.x), static_cast<int>(size.y)}));

    sf::Font general_font;
    if (!general_font.openFromFile("../assets/fonts/Jura-VariableFont_wght.ttf"))
        std::cerr << "Error loading font." << std::endl;
    AnthillInfoText anthill_info_text(general_font);
    anthill_info_text.update(window);

    std::vector<Ant> ants;
    for (int i = 0; i < ANT_COUNT; ++i) {
        ants.emplace_back(i, 1, size);
    }

    sf::Text fps_text(general_font, "", 20);
    fps_text.setFillColor(sf::Color::White);
    fps_text.setPosition({10.f, 10.f});
    int frame_count = 0;
    float time_accumulator = 0.f;

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
                    AnthillDrawable::instance().expand();
                    anthill_info_text.update(window);
                }
            }
        }
        sf::Time dt = clock.restart();
        time_accumulator += dt.asSeconds();
        frame_count++;
        if (time_accumulator >= 1.f) {
            fps_text.setString("FPS: " + std::to_string(static_cast<int>(static_cast<float>(frame_count) / time_accumulator)));
            frame_count = 0;
            time_accumulator = 0.f;
        }

        AnthillDrawable::instance().update(dt);
        for (const Ant& ant : ants) ant.pic->update(dt);

        window.clear();
        window.draw(background_sprite);
        window.draw(AnthillDrawable::instance());

        for (const Ant& ant : ants) window.draw(*ant.pic);

        window.draw(anthill_info_text);
        window.draw(fps_text);
        window.display();
    }
}