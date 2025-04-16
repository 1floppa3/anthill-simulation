#include "EnemyMap.h"
namespace Model{
    EnemyMap::EnemyMap() {}

    void EnemyMap::add_enemy(Model::Enemy *enemy) {
        enemies.push_back(enemy);
    }

    Model::Enemy *EnemyMap::find_enemy() {
        if(enemies.empty())
            return nullptr;
        return enemies.front();
    }

    void EnemyMap::update_enemies(sf::Time dt) {
        for (auto it = enemies.begin(); it != enemies.end(); ++it) {
            (*it)->drawable->update(dt);
        }
    }

    void EnemyMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
        for (auto it = enemies.begin(); it != enemies.end(); ++it) {
            target.draw(*(*it)->drawable);
        }
    }
}