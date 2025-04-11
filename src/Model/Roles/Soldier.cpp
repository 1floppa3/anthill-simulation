#include "Soldier.h"

namespace Model::Roles {

    void Soldier::work(View::AntDrawable& drawable_ant, View::FoodMap& food_map)  {}

    Soldier* Soldier::clone() const {
        return new Soldier(*this);
    }

}