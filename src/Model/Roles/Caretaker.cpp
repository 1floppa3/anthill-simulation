#include <iostream>
#include "Caretaker.h"

void Caretaker::work(View::AntDrawable &drawable_ant, HiveMind &hive_mind) {
}

Caretaker *Caretaker::clone() const {
    return new Caretaker(*this);
}