#pragma once

#include <SFML/Graphics.hpp>

class Anthill final : public sf::Drawable {
    const int contour_points = 20;
    const float init_point_dist = 60.f;
    const float min_dist_delta = -8.f;
    const float max_dist_delta = 32.f;
    const float tile_factor = 0.3f;

    std::vector<float> angles;
    std::vector<float> current_state;

    std::vector<float> animation_start_state;
    std::vector<float> animation_target_state;
    float animation_duration;
    float animation_elapsed;

    sf::VertexArray vertices;
    sf::Texture& texture;
    sf::Transform transform;

    Anthill();
    void update_shape();
    void animate(float dt);
public:
    bool is_animating;
    int age;

    static Anthill& instance();
    Anthill(const Anthill&) = delete;
    Anthill& operator=(const Anthill&) = delete;

    void set_position(const sf::Vector2f& position);
    void expand();
    void update(const sf::Time& dt);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class AnthillInfoText final : public sf::Text {
    const float margin = 32.f;
public:
    explicit AnthillInfoText(const sf::Font& font): Text(font, "", 72) {
        this->setFillColor(sf::Color::White);
    }
    void update(const sf::RenderWindow& window) {
        this->setString("Age: " + std::to_string(Anthill::instance().age));
        this->setPosition({static_cast<float>(window.getSize().x) - this->getLocalBounds().size.x - margin, margin});
    }
};
