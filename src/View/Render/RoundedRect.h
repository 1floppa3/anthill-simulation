#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

namespace View::Render {

    class RoundedRect final: public sf::Shape {
        const unsigned corner_point_count = 20;

        sf::Vector2f size;
        float radius;
    public:
        explicit RoundedRect(const sf::Vector2f& size_ = sf::Vector2f(0,0), const float radius_ = 0):
        size(size_), radius(radius_) {
            update();
        }

        void set_size(const sf::Vector2f& size_) { size = size_; update(); }
        const sf::Vector2f& get_size() const { return size; }

        void set_corners_radius(const float radius_) { radius = radius_; update(); }
        float get_corners_radius() const { return radius; }

        std::size_t getPointCount() const override {
            return corner_point_count * 4;
        }

        sf::Vector2f getPoint(const std::size_t index) const override {
            if (index >= corner_point_count*4)
                return {0,0};

            const float delta_angle = 90.0f/static_cast<float>(corner_point_count - 1);
            sf::Vector2f center;
            const unsigned int center_index = index/corner_point_count;

            switch (center_index)
            {
                case 0: center.x = size.x - radius; center.y = radius; break;
                case 1: center.x = radius; center.y = radius; break;
                case 2: center.x = radius; center.y = size.y - radius; break;
                default: center.x = size.x - radius; center.y = size.y - radius; break;
            }

            return {static_cast<float>(radius*cos(delta_angle*static_cast<float>(index - center_index)*std::numbers::pi/180)+center.x),
                                static_cast<float>(-radius*sin(delta_angle*static_cast<float>(index - center_index)*std::numbers::pi/180)+center.y)};
        }
    };

};