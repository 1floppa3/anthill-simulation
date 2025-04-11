#include "Builder.h"

namespace Model::Roles {

    void Builder::work(View::AntDrawable& drawable_ant, View::FoodMap& hive_mind) {}

    Builder* Builder::clone() const {
        return new Builder(*this);
    }

}