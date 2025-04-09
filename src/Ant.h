#ifndef ANTHILL_SIMULATION_ANT_H
#define ANTHILL_SIMULATION_ANT_H

#include "Roles/Role.h"
#include "Roles/NoRole.h"

class Ant {
private:
    int age, health;
    Role *role;

    void update_role();

    Role *get_new_role() const;

public:
    Ant(int age, int health, Role *role);

    Ant(int age, int health);

    ~Ant();

    void do_work() const;

    bool is_alive() const;
};

#endif //ANTHILL_SIMULATION_ANT_H
