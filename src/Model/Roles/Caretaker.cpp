#include <iostream>
#include "Caretaker.h"

namespace Model::Roles {

    void Caretaker::work(View::AntDrawable &drawable_ant, View::FoodMap &food_map) {
    }

    Caretaker *Caretaker::clone() const {
        return new Caretaker(*this);
    }

}