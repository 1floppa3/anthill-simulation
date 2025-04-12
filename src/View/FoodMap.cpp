#include "../View/FoodMap.h"
#include "../Utils/Random.h"

namespace View {

    void FoodMap::generate_food(const sf::Vector2f &area) {
        FoodPoint *new_food =new FoodPoint({Utils::Random::random(area_margin, area.x - area_margin),
                               Utils::Random::random(area_margin, area.y - area_margin)});
        food_points[new_food] = false;
    }

    void FoodMap::store_food(FoodPoint *food_point) {
        ++stored_food;
        delete food_point;
        food_points.erase(food_point);
    }

    int FoodMap::get_stored_food() const {
        return stored_food;
    }

    void FoodMap::spend_meal() {
        --stored_food;
    }

    FoodPoint *FoodMap::find_closest_food(const AntDrawable &drawable) {
        FoodPoint *closest_food = nullptr;
        float min_distance_squared = std::numeric_limits<float>::max();

        for (auto &food: food_points) {
            if (food.second)
                continue;

            const float distance_squared = (food.first->getPosition() - drawable.get_position()).lengthSquared();
            if (distance_squared < min_distance_squared) {
                min_distance_squared = distance_squared;
                closest_food = food.first;
            }
        }

        if (closest_food) {
            food_points[closest_food] = true;
            return closest_food;
        }
        return nullptr;
    }

    void FoodMap::draw(sf::RenderTarget &target, const sf::RenderStates states) const {
        for (const auto &[point, reserved]: food_points) {
            target.draw(*point, states);
        }
    }

}
