#ifndef ANTHILL_SIMULATION_ROLE_H
#define ANTHILL_SIMULATION_ROLE_H
#include "../Drawable/AntDrawable.h"

class Role{
public:
    virtual ~Role() = default;
    virtual void work(AntDrawable& drawable_ant) const = 0;
};
#endif //ANTHILL_SIMULATION_ROLE_H
