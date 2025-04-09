#ifndef ANTHILL_SIMULATION_NOROLE_H
#define ANTHILL_SIMULATION_NOROLE_H

#include <iostream>
#include "Role.h"

class NoRole : public Role {
public:
    void work(AntDrawable& drawable_ant) const override {
        std::cout << drawable_ant.get_position().x;
    };
};

#endif //ANTHILL_SIMULATION_NOROLE_H
