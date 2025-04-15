#include "AnthillDrawable.h"

#include <cmath>
#include <numbers>

#include "../Utils/Random.h"
#include "../Utils/TextureManager.h"

namespace View {

AnthillDrawable::AnthillDrawable():
    animation_duration(animation_dur),
    animation_elapsed(0.f),
    animating(false),
    vertices(sf::PrimitiveType::TriangleFan),
    texture(Utils::TextureManager::instance().get("../assets/textures/anthill.png"))
{
    texture.setRepeated(true);

    angles.resize(contour_points);
    current_state.resize(contour_points);
    animation_start_state.resize(contour_points);
    animation_target_state.resize(contour_points);
    std::vector<float> distances(contour_points);
    for (int i = 0; i < contour_points; ++i) {
        angles[i] = static_cast<float>(i) * std::numbers::pi_v<float> * 2.0f / static_cast<float>(contour_points);
        const float random_factor = Utils::Random::random(init_min_dist, init_max_dist);
        current_state[i] = init_point_dist * random_factor;
        animation_start_state[i] = init_point_dist * random_factor;
        animation_target_state[i] = init_point_dist * random_factor;
    }
    update_shape();
}
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

void AnthillDrawable::set_position(const sf::Vector2f& position) {
    transform.translate(position);
}
bool AnthillDrawable::is_animating() const {
    return animating;
}

void AnthillDrawable::expand() {
    if (animating)
        return;
    animation_start_state = current_state;
    for (int i = 0; i < contour_points; ++i) {
        const float delta = Utils::Random::random(min_dist_delta, max_dist_delta);
        animation_target_state[i] = current_state[i] + delta;
    }
    animation_elapsed = 0.f;
    animating = true;
}
void AnthillDrawable::update(const sf::Time& dt) {
    if (!animating) return;

    animation_elapsed += dt.asSeconds();
    float factor = animation_elapsed / animation_duration;
    if (factor > 1.f)
        factor = 1.f;

    // interpolation
    for (int i = 0; i < contour_points; ++i)
        current_state[i] = animation_start_state[i] + (animation_target_state[i] - animation_start_state[i]) * factor;
    update_shape();

    if (factor >= 1.f) {
        current_state = animation_target_state;
        animating = false;
    }
}

void AnthillDrawable::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.texture = &texture;
    states.transform *= transform;
    target.draw(vertices, states);
}

}