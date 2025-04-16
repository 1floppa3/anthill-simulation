#ifndef ANTHILL_SIMULATION_ENEMYMAP_H
#define ANTHILL_SIMULATION_ENEMYMAP_H

#include <map>
#include <list>
#include "../Enemy.h"

namespace Model {
    class EnemyMap : public sf::Drawable {
        std::list<Model::Enemy *> enemies;
    public:
        EnemyMap();

        void add_enemy(Model::Enemy *enemy);

        Model::Enemy *find_enemy();

        void update_enemies(sf::Time dt);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    };
}

#endif //ANTHILL_SIMULATION_ENEMYMAP_H
