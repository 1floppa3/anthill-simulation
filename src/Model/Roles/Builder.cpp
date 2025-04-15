#include <iostream>
#include "Builder.h"
#include "../../Core/Simulation.h"

namespace Model::Roles {

    void Builder::work(View::AntDrawable& drawable_ant, Model::HiveMind& hive_mind) {
        const sf::Vector2f anthill_pos = Core::g_anthill.drawable->get_position();
        if (!is_bringing) {
            if (!wood_point) {
                View::WoodPoint* new_wood_point = hive_mind.find_closest_wood(drawable_ant);
                if (new_wood_point != nullptr) {
                    wood_point = new_wood_point;
                    drawable_ant.go_to(new_wood_point->getPosition());
                }
            } else {
                if (drawable_ant.has_reached(wood_point->getPosition())) {
                    is_bringing = true;
                    drawable_ant.go_to(anthill_pos);
                }
            }
        }
        else {
            wood_point->setPosition(drawable_ant.get_position());
            if (drawable_ant.has_reached(anthill_pos)) {
                hive_mind.store_wood(wood_point);
                wood_point = nullptr;
                is_bringing = false;
            }
        }
    }

    Builder* Builder::clone() const {
        return new Builder(*this);
    }

    Builder::Builder():wood_point(nullptr), is_bringing(false) {

    }

}