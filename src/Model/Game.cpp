#include "Game.h"
#include <cmath>
#include "EnemyController.h"
#include "../Core/EventManager.h"
#include "../Core/Simulation.h"
#include <valarray>

Game::Game(Model::Anthill& anthill) : anthill(&anthill), enemy_controller(new EnemyController(*this)) { }

Model::Ant* Game::find_closest_ant(const sf::Vector2f& position, float field_of_vision) const
{
	if (anthill->ants.size() == 0)
		return nullptr;

	Model::Ant* closest_ant = nullptr;
	float distance, closest_distance = field_of_vision + 1;

	for (auto ant : anthill->ants) {
		auto [x, y] = ant.drawable->get_position();
		distance = std::sqrt((position.x - x) * (position.x - x) + (position.y - y) * (position.y - y));
		if (distance > field_of_vision)
			continue;
		if (distance < closest_distance) {
			closest_distance = distance;
			closest_ant = &ant;
		}
	}
	return closest_ant;
}

void Game::update(const sf::Vector2u& resolution, const sf::Time& dt)
{
	for (auto& ant : anthill->ants) {
		if (ant.is_alive()) {
			ant.detect_objects(Core::g_event_manager);
			ant.do_work(Core::g_anthill.hive_mind);
			ant.drawable->update_text(ant);
			ant.drawable->update(dt);
		}
	}
	enemy_controller->LoadTick();
}
