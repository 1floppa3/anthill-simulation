#ifndef ANTHILL_SIMULATION_ROLE_H
#define ANTHILL_SIMULATION_ROLE_H
class Role{
public:
    virtual ~Role() = default;
    virtual void work() const = 0;
};
#endif //ANTHILL_SIMULATION_ROLE_H
