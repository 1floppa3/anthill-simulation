#include "Soldier.h"

void Soldier::work(AntDrawable& drawable_ant) const {}

Soldier* Soldier::clone() const {
    return new Soldier(*this);
}