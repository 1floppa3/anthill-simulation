#ifndef ANTHILL_SIMULATION_SOLDIER_H
#define ANTHILL_SIMULATION_SOLDIER_H

#include "Role.h"

class Soldier: public Role{
public:
    void work(AntDrawable& drawable_ant) const override;
};
#endif //ANTHILL_SIMULATION_SOLDIER_H
