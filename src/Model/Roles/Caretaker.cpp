#include <iostream>
#include "Caretaker.h"

namespace Model::Roles {

    void Caretaker::work(View::AntDrawable &drawable_ant, Model::HiveMind& hive_mind) {
    }

    Caretaker *Caretaker::clone() const {
        return new Caretaker(*this);
    }

}