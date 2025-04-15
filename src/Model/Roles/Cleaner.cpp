#include "Cleaner.h"

namespace Model::Roles {

    void Cleaner::work(View::AntDrawable& drawable_ant, Model::HiveMind& hive_mind) {}

    Cleaner* Cleaner::clone() const {
        return new Cleaner(*this);
    }

}