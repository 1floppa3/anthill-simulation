#ifndef ANTHILL_SIMULATION_ENEMY_H
#define ANTHILL_SIMULATION_ENEMY_H
#include "Entity.h"
#include "../View/AntDrawable.h"

namespace Model{
    class Enemy: public Entity{
    private:
    public:
        explicit Enemy(const sf::Vector2u &area);
        View::AntDrawable *drawable;
    };
}

#endif //ANTHILL_SIMULATION_ENEMY_H
