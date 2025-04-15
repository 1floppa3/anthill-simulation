#ifndef GAME_H
#define GAME_H

#include <list>
#include "Anthill.h"
#include "EnemyController.h"
#include "FoodPoint.h"

class Anthill;
class EnemyController;
class FoodPoint;

class Game {
private:
	Anthill* anthill;
	EnemyController* enemy_controller;
	std::list<FoodPoint> food;
public:
	void spawn_food();
	Ant* find_closest_ant(const sf::Vector2f& position, float field_of_vision) const;
	
};

#endif