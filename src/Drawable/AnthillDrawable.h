#pragma once

#include <SFML/Graphics.hpp>

class AnthillDrawable final : public sf::Drawable {
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
    bool animating;

    sf::VertexArray vertices;
    sf::Texture& texture;
    sf::Transform transform;

    AnthillDrawable();
    void update_shape();
public:
    int day_counter;

    static AnthillDrawable& instance();
    AnthillDrawable(const AnthillDrawable&) = delete;
    AnthillDrawable& operator=(const AnthillDrawable&) = delete;

    void set_position(const sf::Vector2f& position);
    [[nodiscard]] bool is_animating() const;

    void expand();
    void update(const sf::Time& dt);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
