#include <iostream>
#include "EventManager.h"
#include "../Model/HiveMind.h"
#include "../View/Points/FoodPoint.h"
#include "../View/Points/WoodPoint.h"
#include "../Utils/Random.h"

namespace Core {

    void EventManager::set_hive_mind(Model::HiveMind *hive_mind) {
        this->hive_mind = hive_mind;
    }

    void EventManager::generate_food(const sf::Vector2f &area) {
        View::FoodPoint *new_food = new View::FoodPoint({Utils::Random::random(area_margin, area.x - area_margin),
                                                         Utils::Random::random(area_margin, area.y - area_margin)});
        undetected_food.push_back(new_food);
    }
    void EventManager::generate_wood(const sf::Vector2f &area) {
        View::WoodPoint *new_wood = new View::WoodPoint({Utils::Random::random(area_margin, area.x - area_margin),
                                                         Utils::Random::random(area_margin, area.y - area_margin)});
        undetected_wood.push_back(new_wood);
    }

    void EventManager::detect_objects(View::AntDrawable &ant_drawable) {
        auto [x, y] = ant_drawable.get_position();
        float x_left_up = x - ant_drawable.object_detection_area, y_left_up = y - ant_drawable.object_detection_area;
        float x_right_down = x + ant_drawable.object_detection_area, y_right_down =
                y + ant_drawable.object_detection_area;

        for (auto it = undetected_wood.begin(); it != undetected_wood.end();) {
            auto [f_x, f_y] = (*it)->get_pos();
            if (x_left_up <= f_x && f_x <= x_right_down &&
                y_left_up <= f_y && f_y <= y_right_down) {
                hive_mind->add_wood(*it);
                it = undetected_wood.erase(it);
            } else
                ++it;
        }

        for (auto it = undetected_food.begin(); it != undetected_food.end();) {
            auto [f_x, f_y] = (*it)->get_pos();
            if (x_left_up <= f_x && f_x <= x_right_down &&
                y_left_up <= f_y && f_y <= y_right_down) {
                hive_mind->add_food(*it);
                it = undetected_food.erase(it);
            } else
                ++it;
        }
    }
}