#include "Forager.h"

#include "../../Core/Simulation.h"

namespace Model::Roles {

    void Forager::work(View::AntDrawable &drawable_ant, View::FoodMap &food_map) {
        const sf::Vector2f anthill_pos = Core::g_anthill.drawable->get_position();

        if (!is_bringing) {
            if (!food_point) {
                View::FoodPoint* new_food_point = food_map.find_closest_food(drawable_ant);
                if (new_food_point != nullptr) {
                    food_point = new_food_point;
                    drawable_ant.go_to(food_point->getPosition());
                }
            } else {
                if (drawable_ant.has_reached(food_point->getPosition())) {
                    is_bringing = true;
                    drawable_ant.go_to(anthill_pos);
                }
            }
        }
        else {
            food_point->setPosition(drawable_ant.get_position());
            if (drawable_ant.has_reached(anthill_pos)) {
                food_map.store_food(food_point);
                food_point = nullptr;
                is_bringing = false;
            }
        }
    }

    Forager::Forager() : food_point(nullptr), is_bringing(false) {}

    Forager *Forager::clone() const {
        return new Forager(*this);
    }

}
