#include "Cleaner.h"

void Cleaner::work(View::AntDrawable& drawable_ant, HiveMind& hive_mind) {}

Cleaner* Cleaner::clone() const {
    return new Cleaner(*this);
}