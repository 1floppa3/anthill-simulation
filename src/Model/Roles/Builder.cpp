#include "Builder.h"

namespace Model::Roles {

    void Builder::work(View::AntDrawable& drawable_ant, View::FoodMap& food_map) {}

    Builder* Builder::clone() const {
        return new Builder(*this);
    }

}