#include "Soldier.h"

void Soldier::work(View::AntDrawable& drawable_ant) const {}

Soldier* Soldier::clone() const {
    return new Soldier(*this);
}