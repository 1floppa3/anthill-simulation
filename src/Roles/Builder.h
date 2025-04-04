#ifndef ANTHILL_SIMULATION_BUILDER_H
#define ANTHILL_SIMULATION_BUILDER_H

#include "Role.h"

class Builder: public Role{
    void work() const override;
};
#endif //ANTHILL_SIMULATION_BUILDER_H
