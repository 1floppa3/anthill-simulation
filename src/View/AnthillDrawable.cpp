#include "AnthillDrawable.h"

#include <cmath>
#include <numbers>

#include "../Core/Simulation.h"
#include "../Utils/Random.h"
#include "../Utils/TextureManager.h"

namespace View {

    void AnthillDrawable::update_shape() {
        vertices.clear();
        vertices.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::White, sf::Vector2f(0, 0)));

        std::vector<sf::Vector2f> points;
        for (int i = 0; i < contour_points; ++i) {
            float x = current_state[i] * std::cos(angles[i]);
            float y = current_state[i] * std::sin(angles[i]);
            points.emplace_back(x, y);
            vertices.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::White, sf::Vector2f(0, 0)));
        }
        if (!points.empty())
            vertices.append(sf::Vertex(points[0], sf::Color::White, sf::Vector2f(0, 0)));

        float minX = std::numeric_limits<float>::max();
        float minY = std::numeric_limits<float>::max();
        float maxX = std::numeric_limits<float>::lowest();
        float maxY = std::numeric_limits<float>::lowest();
        for (size_t i = 0; i < vertices.getVertexCount(); ++i) {
            const sf::Vector2f pos = vertices[i].position;
            if (pos.x < minX) minX = pos.x;
            if (pos.y < minY) minY = pos.y;
            if (pos.x > maxX) maxX = pos.x;
            if (pos.y > maxY) maxY = pos.y;
        }
        for (size_t i = 0; i < vertices.getVertexCount(); ++i) {
            const sf::Vector2f pos = vertices[i].position;
            const float texX = (pos.x - minX) * tile_factor;
            const float texY = (pos.y - minY) * tile_factor;
            vertices[i].texCoords = sf::Vector2f(texX, texY);
        }
    }
    float AnthillDrawable::get_point_max_dist(const int point_idx, const sf::Vector2f& area) const {
        const float cosTheta = std::cos(angles[point_idx]);
        const float sinTheta = std::sin(angles[point_idx]);

        float allowedX = std::numeric_limits<float>::infinity();
        float allowedY = std::numeric_limits<float>::infinity();

        if (cosTheta > 0.f)
            allowedX = (area.x - window_margin - get_position().x) / cosTheta - current_state[point_idx];
        else if (cosTheta < 0.f)
            allowedX = (get_position().x - window_margin) / -cosTheta - current_state[point_idx];

        if (sinTheta > 0.f)
            allowedY = (area.y - window_margin - get_position().y) / sinTheta - current_state[point_idx];
        else if (sinTheta < 0.f)
            allowedY = (get_position().y - window_margin) / -sinTheta - current_state[point_idx];
        return std::min(allowedX, allowedY);
    }

    AnthillDrawable::AnthillDrawable():
    angles(contour_points), current_state(contour_points),
    vertices(sf::PrimitiveType::TriangleFan),
    texture(Utils::TextureManager::instance().get(texture_path)) {
        texture.setRepeated(true);

        animation.start_state.resize(contour_points);
        animation.target_state.resize(contour_points);

        float sum = 0.f;
        for (int i = 0; i < contour_points; ++i) {
            angles[i] = static_cast<float>(i) * std::numbers::pi_v<float> * 2.0f / static_cast<float>(contour_points);
            const float random_factor = Utils::Random::random(init_min_dist, init_max_dist);
            const float dist = init_point_dist * random_factor;
            current_state[i] = dist;
            animation.start_state[i] = dist;
            animation.target_state[i] = dist;
            sum += dist;
        }

        // приблизительная площадь (как у круга)
        const float avg_radius = sum / static_cast<float>(contour_points);
        area = std::numbers::pi_v<float> * avg_radius * avg_radius;

        update_shape();
    }

    void AnthillDrawable::set_position(const sf::Vector2f& position) {
        transform.translate(position);
    }
    sf::Vector2f AnthillDrawable::get_position() const {
        return transform.transformPoint(sf::Vector2f(0.f, 0.f));
    }
    float AnthillDrawable::get_area() const {
        return area;
    }

    bool AnthillDrawable::is_animating() const {
        return animation.processing;
    }

    void AnthillDrawable::expand(const sf::Vector2u& area) {
        if (animation.processing)
            return;
        animation.start_state = current_state;
        for (int i = 0; i < contour_points; ++i) {
            const float random_expansion = Utils::Random::random(min_dist_delta, max_dist_delta);
            float max_dist_to_border = get_point_max_dist(i, sf::Vector2f(area));
            const float delta = std::min(random_expansion, max_dist_to_border);
            animation.target_state[i] = current_state[i] + delta;
        }
        animation.elapsed = sf::Time::Zero;
        animation.processing = true;
    }

    void AnthillDrawable::update(const sf::Time& dt) {
        if (!animation.processing) return;

        animation.elapsed += dt;
        float factor = animation.elapsed / animation_duration;
        if (factor > 1.f)
            factor = 1.f;

        // interpolation
        for (int i = 0; i < contour_points; ++i)
            current_state[i] = animation.start_state[i] + (animation.target_state[i] - animation.start_state[i]) * factor;
        update_shape();

        float sum = 0.f;
        for (int i = 0; i < contour_points; ++i)
            sum += current_state[i];

        // приблизительная площадь (как у круга)
        const float avg_radius = sum / static_cast<float>(contour_points);
        area = std::numbers::pi_v<float> * avg_radius * avg_radius;

        if (factor >= 1.f) {
            current_state = animation.target_state;
            animation.processing = false;
            Core::g_logger.add_message("<color=#4778b3>[system]</color> Anthill is expanded. New area: " + std::format("{:.2f}", area/10000.f));
        }
    }

    void AnthillDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.texture = &texture;
        states.transform *= transform;
        target.draw(vertices, states);
    }

}