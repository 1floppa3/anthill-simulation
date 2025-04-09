#include "Caretaker.h"

void Caretaker::work(AntDrawable& drawable_ant) const {

}

Caretaker* Caretaker::clone() const {
    return new Caretaker(*this);
}