#include "Game.h"
#include <cmath>

#include <valarray>

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
