#include "Builder.h"

void Builder::work(View::AntDrawable& drawable_ant, HiveMind& hive_mind) {}

Builder* Builder::clone() const {
    return new Builder(*this);
}