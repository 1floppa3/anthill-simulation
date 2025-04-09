#pragma once

#include <SFML/Graphics.hpp>

namespace View {

class AnthillDrawable final : public sf::Drawable {
    const int contour_points = 20;
    const float init_point_dist = 60.f;
    const float init_min_dist = .8f;
    const float init_max_dist = 1.2f;
    const float min_dist_delta = -4.f;
    const float max_dist_delta = 10.f;
    const float tile_factor = .3f;
    const float animation_dur = .3f;

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

    void update_shape();
public:
    AnthillDrawable();

    void set_position(const sf::Vector2f& position);
    [[nodiscard]] bool is_animating() const;

    void expand();
    void update(const sf::Time& dt);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

}