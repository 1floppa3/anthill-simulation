#include "Cleaner.h"

namespace Model::Roles {

    void Cleaner::work(View::AntDrawable& drawable_ant, View::FoodMap& hive_mind) {}

    Cleaner* Cleaner::clone() const {
        return new Cleaner(*this);
    }

}