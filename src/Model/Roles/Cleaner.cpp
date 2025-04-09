#include "Cleaner.h"

void Cleaner::work(View::AntDrawable& drawable_ant) const {}

Cleaner* Cleaner::clone() const {
    return new Cleaner(*this);
}