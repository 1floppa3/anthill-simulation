#ifndef GAME_H
#define GAME_H

#include <list>
#include "Anthill.h"
#include "EnemyController.h"
#include <SFML/System/Time.hpp>

class Anthill;
class EnemyController;

class Game {
private:
	Model::Anthill* anthill;
	EnemyController* enemy_controller;
public:
	Game(Model::Anthill& anthill);
	~Game() { delete enemy_controller; }
	Model::Ant* find_closest_ant(const sf::Vector2f& position, float field_of_vision) const;
	void update(const sf::Vector2u& resolution, const sf::Time& dt);
};


#endif