#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#define ENEMY_DEFAULT_HP 100
#define ENEMY_DEFAULT_DAMAGE 10
#define ENEMY_DEFAULT_FIELD_OF_VISION 10

#include <vector>
#include "Enemy.h"
#include "Ant.h"
#include "Game.h"
#include "IAttackable.h"

class Enemy;
class Ant;
class Game;

class EnemyController {
private:
	Game& game;
	struct DetectedAnt{
		Ant* ant;
		size_t ticks_since_detection;
	};
	std::vector<Enemy> enemies;
	std::list<DetectedAnt> recently_detected;

	void DetectClosestTarget();

	void AttackTargets();
public:
	EnemyController(Game& game) : enemies(), recently_detected(), game(game) {}

	void SpawnEnemy(const sf::Vector2f& position, int hp = ENEMY_DEFAULT_HP, int damage = ENEMY_DEFAULT_DAMAGE);

	void LoadTick();
};

#endif