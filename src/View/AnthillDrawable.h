#pragma once

#include <SFML/Graphics.hpp>

namespace View {

    class AnthillDrawable final : public sf::Drawable {
        const float window_margin = 25.f;
        static constexpr int contour_points = 20;
        const float init_point_dist = 60.f;
        const float init_min_dist = .8f;
        const float init_max_dist = 1.2f;
        const float min_dist_delta = -8.f;
        const float max_dist_delta = 32.f;
        const float tile_factor = .4f;
        const sf::Time animation_duration = sf::seconds(1.5f);

        std::vector<float> angles;
        std::vector<float> current_state;

        struct AnimationData {
            std::vector<float> start_state;
            std::vector<float> target_state;
            sf::Time elapsed = sf::Time::Zero;
            bool processing = false;
        } animation;

        sf::VertexArray vertices;
        sf::Texture& texture;
        sf::Transform transform;
        float area;

        void update_shape();
        [[nodiscard]] float get_point_max_dist(int point_idx, const sf::Vector2f &area) const;

    public:
        AnthillDrawable();

        void set_position(const sf::Vector2f& position);
        [[nodiscard]] sf::Vector2f get_position() const;
        [[nodiscard]] float get_area() const;
        [[nodiscard]] bool is_animating() const;

        void expand(const sf::Vector2u& area);

        void update(const sf::Time& dt);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };

}