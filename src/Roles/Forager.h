#ifndef ANTHILL_SIMULATION_FORAGER_H
#define ANTHILL_SIMULATION_FORAGER_H

#include "Role.h"

class Forager: public Role{
    void work(AntDrawable& drawable_ant) const override;
};
#endif //ANTHILL_SIMULATION_FORAGER_H
