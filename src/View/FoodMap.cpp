#include "../View/FoodMap.h"
#include "../Utils/Random.h"

namespace View {

    void FoodMap::generate_food(const sf::Vector2f& area) {
        const Food new_food = {
            new FoodPoint({Utils::Random::random(area_margin, area.x - area_margin),
                                        Utils::Random::random(area_margin, area.y - area_margin)}),
            false
        };
        food_points.push_back(new_food);
    }
    void FoodMap::add_food(FoodPoint* food_point) {
        const Food new_food = {food_point, false};
        food_points.push_back(new_food);
    }
    void FoodMap::store_food(const FoodPoint* food_point) {
        ++stored_food;
        for (auto it = food_points.begin(); it != food_points.end(); ) {
            if (it->point == food_point) {
                delete it->point;
                it = food_points.erase(it);
            } else {
                ++it;
            }
        }
    }

    int FoodMap::get_stored_food() const {
        return stored_food;
    }
    void FoodMap::spend_meal() {
        --stored_food;
    }

    FoodPoint* FoodMap::find_closest_food(const AntDrawable& drawable) {
        Food* closest_food = nullptr;
        float min_distance_squared = std::numeric_limits<float>::max();

        for (auto &food: food_points) {
            if (food.reserved || food.point == nullptr)
                continue;

            const float distance_squared = (food.point->getPosition() - drawable.get_position()).lengthSquared();
            if (distance_squared < min_distance_squared) {
                min_distance_squared = distance_squared;
                closest_food = &food;
            }
        }

        if (closest_food) {
            closest_food->reserved = true;
            return closest_food->point;
        }

        return nullptr;
    }

    void FoodMap::draw(sf::RenderTarget& target, const sf::RenderStates states) const {
        for (const auto&[point, reserved]: food_points) {
            target.draw(*point, states);
        }
    }

}
