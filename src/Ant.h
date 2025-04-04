#ifndef ANTHILL_SIMULATION_ANT_H
#define ANTHILL_SIMULATION_ANT_H

#include "Roles/Role.h"
#include "Roles/NoRole.h"

class Ant {
private:
    int age, health;
    Role *role;

    void updateRole();

    Role *getNewRole() const;

public:
    Ant(int age, int health, Role *role);

    Ant(int age, int health);

    ~Ant();

    void doWork() const;

    bool isAlive() const;
};

#endif //ANTHILL_SIMULATION_ANT_H
