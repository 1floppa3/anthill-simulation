#include "Builder.h"

void Builder::work(View::AntDrawable& drawable_ant) const {}

Builder* Builder::clone() const {
    return new Builder(*this);
}