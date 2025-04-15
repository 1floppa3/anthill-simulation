#include <iostream>
#include "FoodMap.h"
#include "../../Utils/Random.h"


namespace Model {
    Model::FoodMap::FoodMap(Model::Store& store):store(store){};

    void Model::FoodMap::store_food(View::FoodPoint *food_point) {
        store.increase(1);
        delete food_point;
        food_points.erase(food_point);
    }

    void FoodMap::add_food(View::FoodPoint* food_point) {
        if(food_points.count(food_point) == 0)
            food_points[food_point] = false;
        else
            std::cout << "smth wrong food event_manager";
    }

    View::FoodPoint *FoodMap::find_closest_food(const View::AntDrawable &drawable) {
        View::FoodPoint *closest_food = nullptr;
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
