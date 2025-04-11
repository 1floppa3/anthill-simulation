#include "Cleaner.h"

namespace Model::Roles {

    void Cleaner::work(View::AntDrawable& drawable_ant, View::FoodMap& food_map) {}

    Cleaner* Cleaner::clone() const {
        return new Cleaner(*this);
    }

}