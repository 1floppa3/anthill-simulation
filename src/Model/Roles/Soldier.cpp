#include "Soldier.h"

namespace Model::Roles {

    void Soldier::work(View::AntDrawable& drawable_ant, Model::HiveMind& hive_mind)  {
        Model::Enemy* enemy = hive_mind.get_enemy();
        if(enemy == nullptr)
            return;
        drawable_ant.go_to(enemy->drawable->get_position(), false);
    }

    Soldier* Soldier::clone() const {
        return new Soldier(*this);
    }

}