#ifndef ANTHILL_SIMULATION_NOROLE_H
#define ANTHILL_SIMULATION_NOROLE_H

#include "Role.h"

class NoRole : public Role {
public:
    void work() const override {};
};

#endif //ANTHILL_SIMULATION_NOROLE_H
