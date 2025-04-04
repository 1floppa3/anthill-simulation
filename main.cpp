#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Anthill {
    static constexpr float initial_radius = 50.f;
    static constexpr int shape_count = 6;
    static constexpr auto color = sf::Color(139, 69, 19);
    static constexpr float scale_factor = 0.5f;

    sf::CircleShape model;
    int level = 1;

public:
    explicit Anthill(const sf::Vector2u& size): model(initial_radius, shape_count) {
        model.setFillColor(color);
        model.setOrigin({initial_radius, initial_radius});
        update_position(size);
    }

    void update_position(const sf::Vector2u& size) {
        model.setPosition({static_cast<float>(size.x) / 4.f, static_cast<float>(size.y) / 2.f});
    }

    void upgrade() {
        level++;
        float new_scale = 1.0f + scale_factor*static_cast<float>(level - 1);
        model.setScale({new_scale, new_scale});
    }

    void downgrade() {
        level = std::max(1, level - 1);
        float new_scale = 1.0f + scale_factor*static_cast<float>(level - 1);
        model.setScale({new_scale, new_scale});
    }

    void update(sf::RenderWindow& window) const {
        window.draw(model);
    }
};

int main() {
    bool is_fullscreen = false;
    sf::Vector2u size(800, 600);
    sf::RenderWindow window(
        sf::VideoMode(size),
        "Anthill simulation",
        sf::Style::Close | sf::Style::Resize,
        sf::State::Windowed);
    window.setVerticalSyncEnabled(true);

    Anthill anthill(window.getSize());

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                const sf::Keyboard::Scancode keycode = keyPressed->scancode;
                if (keycode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                } else if (keycode == sf::Keyboard::Scancode::Left || keycode == sf::Keyboard::Scancode::A) {
                    anthill.downgrade();
                } else if (keycode == sf::Keyboard::Scancode::Right || keycode == sf::Keyboard::Scancode::D) {
                    anthill.upgrade();
                } else if (keycode == sf::Keyboard::Scancode::F11) {
                    is_fullscreen = !is_fullscreen;
                    if (is_fullscreen) {
                        window.create(sf::VideoMode::getDesktopMode(),
                            "Anthill simulation",
                            sf::Style::Default,
                            sf::State::Fullscreen);
                    } else {
                        window.create(sf::VideoMode(size),
                            "Anthill simulation",
                            sf::Style::Close | sf::Style::Resize);
                    }
                    window.setVerticalSyncEnabled(true);
                    anthill.update_position(window.getSize());
                }
            } else if (const auto* resized = event->getIf<sf::Event::Resized>()) {
                sf::FloatRect visibleArea({0, 0}, {static_cast<float>(resized->size.x), static_cast<float>(resized->size.y)});
                window.setView(sf::View(visibleArea));
                anthill.update_position(window.getSize());
                size = resized->size;
            }
        }

        window.clear(sf::Color(70, 200, 60));
        anthill.update(window);
        window.display();
    }
}