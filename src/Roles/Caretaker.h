#ifndef ANTHILL_SIMULATION_CARETAKER_H
#define ANTHILL_SIMULATION_CARETAKER_H

#include "Role.h"

class Caretaker : public Role {
public:
    void work(AntDrawable& drawable_ant) const override;
};

#endif //ANTHILL_SIMULATION_CARETAKER_H
