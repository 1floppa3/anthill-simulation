#pragma once

#include <SFML/Graphics.hpp>

#include "UI/AntInfoText.h"

namespace View {

    class AntDrawable final : public sf::Drawable {
        const std::string texture_path = "../assets/textures/ant.png";
        const float base_speed = 2.f;
        const float sprite_scale = 2.f;
        const float acceleration = 200.f;
        const float max_speed = 100.f;
        const float reach_threshold = 4.0f;

        const sf::Texture& texture;
        sf::Sprite sprite;
        sf::Vector2f velocity;
        sf::Vector2u area;
        sf::Color color;

        struct AnimationData {
            const int frame_count = 2;
            const float frame_time = 0.2f;
            int current_frame = 0;
            float elapsed_time = 0.f;
            sf::Vector2i frame_size;
        } animation;

        UI::AntInfoText info_text;
    public:
        float object_detection_area = 100;

        explicit AntDrawable(const sf::Vector2u& area_);
        AntDrawable* clone() const;

        sf::Vector2f get_position() const;
        sf::FloatRect get_global_bounds() const;
        void go_to(const sf::Vector2f& dest);
        void reset_speed();
        bool has_reached(const sf::Vector2f &target) const;
        void set_color(const sf::Color &color);

        void update(const sf::Time& dt);
        void update_text(const Model::Ant& ant);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };

}
