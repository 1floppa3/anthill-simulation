#ifndef ANTHILL_SIMULATION_FORAGER_H
#define ANTHILL_SIMULATION_FORAGER_H

#include "Role.h"

class Forager: public Role{
    void work() const override;
};
#endif //ANTHILL_SIMULATION_FORAGER_H
