#include "Cleaner.h"

void Cleaner::work(AntDrawable& drawable_ant) const {}

Cleaner* Cleaner::clone() const {
    return new Cleaner(*this);
}