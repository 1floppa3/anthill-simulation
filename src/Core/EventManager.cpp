#include <iostream>
#include "EventManager.h"
#include "../View/FoodMap.h"
#include "../View/FoodPoint.h"
#include "../Utils/Random.h"

namespace Core {

    void EventManager::set_food_map(View::FoodMap *food_map) {
        this->food_map = food_map;
    }

    void EventManager::generate_food(const sf::Vector2f &area) {
        View::FoodPoint *new_food = new View::FoodPoint({Utils::Random::random(area_margin, area.x - area_margin),
                                                         Utils::Random::random(area_margin, area.y - area_margin)});
        undetected_food.push_back(new_food);
    }

    void EventManager::detect_food(View::AntDrawable &ant_drawable) {
        auto [x, y] = ant_drawable.get_position();
        float x_left_up = x - ant_drawable.object_detection_area, y_left_up = y - ant_drawable.object_detection_area;
        float x_right_down = x + ant_drawable.object_detection_area, y_right_down =
                y + ant_drawable.object_detection_area;
        for (auto it = undetected_food.begin(); it != undetected_food.end();) {
            auto [f_x, f_y] = (*it)->get_pos();
            if (x_left_up <= f_x && f_x <= x_right_down &&
                y_left_up <= f_y && f_y <= y_right_down) {
                food_map->add_food(*it);
                it = undetected_food.erase(it);
            } else
                ++it;
        }
    }
}