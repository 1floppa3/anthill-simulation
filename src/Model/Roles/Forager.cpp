#include <iostream>
#include "Forager.h"

void Forager::work(View::AntDrawable& drawable_ant) const {}

Forager* Forager::clone() const {
    return new Forager(*this);
}