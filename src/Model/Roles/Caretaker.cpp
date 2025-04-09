#include "Caretaker.h"

void Caretaker::work(View::AntDrawable& drawable_ant) const {

}

Caretaker* Caretaker::clone() const {
    return new Caretaker(*this);
}