#include "EnemyController.h"
#include <SFML/System/Vector2.hpp>

void EnemyController::SpawnEnemy(const sf::Vector2f& position, int hp, int damage)
{
    enemies.push_back(Enemy(hp, damage, position));
}

void EnemyController::LoadTick()
{
    DetectClosestTarget();
    AttackTargets();
}

void EnemyController::DetectClosestTarget()
{
    Ant* closest_ant;
    for (auto enemy : enemies) {
        closest_ant = game.find_closest_ant(enemy.get_position(), ENEMY_DEFAULT_FIELD_OF_VISION);
        if (closest_ant != nullptr) {
            enemy.target = closest_ant;
            continue;
        }
        // Find from detected
    }
}

void EnemyController::AttackTargets()
{
    for (auto enemy : enemies) {
        enemy.attack();
    }
}
