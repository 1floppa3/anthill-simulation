#ifndef ANTHILL_SIMULATION_CLEANER_H
#define ANTHILL_SIMULATION_CLEANER_H

#include "Role.h"

class Cleaner: public Role{
    void work(AntDrawable& drawable_ant) const override;
};
#endif //ANTHILL_SIMULATION_CLEANER_H
