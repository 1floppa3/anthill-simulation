#ifndef GAME_H
#define GAME_H

#include <list>
#include "Anthill.h"
#include "EnemyController.h"

class Anthill;
class EnemyController;

class Game {
private:
	Model::Anthill* anthill;
	EnemyController* enemy_controller;
public:
	Model::Ant* find_closest_ant(const sf::Vector2f& position, float field_of_vision) const;
};


#endif