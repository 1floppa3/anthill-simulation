#include "Soldier.h"

void Soldier::work(View::AntDrawable& drawable_ant,  HiveMind& hive_mind)  {}

Soldier* Soldier::clone() const {
    return new Soldier(*this);
}