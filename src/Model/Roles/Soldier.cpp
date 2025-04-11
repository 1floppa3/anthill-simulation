#include "Soldier.h"

namespace Model::Roles {

    void Soldier::work(View::AntDrawable& drawable_ant, View::FoodMap& hive_mind)  {}

    Soldier* Soldier::clone() const {
        return new Soldier(*this);
    }

}