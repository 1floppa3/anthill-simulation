#include "Forager.h"

#include "../../Core/Simulation.h"

namespace Model::Roles {

    void Forager::work(View::AntDrawable &drawable_ant, Model::HiveMind& hive_mind) {
        const sf::Vector2f anthill_pos = Core::g_anthill.drawable->get_position();

        if (!is_bringing) {
            if (!food_point) {
                View::FoodPoint* new_food_point = hive_mind.find_closest_food(drawable_ant);
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
            const sf::FloatRect ant_bounds = drawable_ant.get_global_bounds();
            const sf::Vector2f food_pos(ant_bounds.position.x + ant_bounds.size.x / 2.f,
                ant_bounds.position.y + ant_bounds.size.y + food_point->get_global_bounds().size.y / 2.f);
            food_point->setPosition(food_pos);
            if (drawable_ant.has_reached(anthill_pos)) {
                hive_mind.store_food(food_point);
                food_point = nullptr;
                is_bringing = false;
                drawable_ant.reset_speed();
            }
        }
    }

    Forager::Forager() : food_point(nullptr), is_bringing(false) {}

    Forager *Forager::clone() const {
        return new Forager(*this);
    }

}
