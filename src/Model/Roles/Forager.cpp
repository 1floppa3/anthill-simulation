#include <iostream>
#include "Forager.h"

void Forager::work(View::AntDrawable &drawable_ant, HiveMind &hive_mind) {
    auto [x, y] = drawable_ant.get_position();
    if (food_point == nullptr && !is_bringing) {
        FoodPoint *new_food_point = hive_mind.get_food_point();
        if (new_food_point != nullptr) {
            food_point = new_food_point;
            drawable_ant.go_to(food_point->x, food_point->y);
        }
    }

    if (food_point != nullptr && !is_bringing) {
        if (food_point->compare_coords(x, y)) {
            food_point->take_food();
            is_bringing = true;
            drawable_ant.go_to(hive_mind.x_anthill, hive_mind.y_anthill);
            if (food_point->is_empty()) {
                hive_mind.remove_point(food_point);
                food_point = nullptr;
            }
        };
    }

    if (is_bringing) {
        if (std::abs(hive_mind.x_anthill - x) < 40 && std::abs(hive_mind.y_anthill - y) < 40) {
            is_bringing = false;
        }
    }
}

Forager::Forager() : food_point(nullptr), is_bringing(false) {}

Forager *Forager::clone() const {
    return new Forager(*this);
}