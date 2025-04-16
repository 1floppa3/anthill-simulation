#include "Enemy.h"
#include <cmath>

void Enemy::deal_damage(int damage)
{
	if (damage >= hp)
		hp = 0; // Perhaps should do some calls in the case of death
	else
		hp -= damage;
}

void Enemy::attack()
{
	auto [x, y] = target->get_position();
	float distance_to_target = std::sqrt((position.x - x) * (position.x - x) + (position.y - y) * (position.y - y));
	if (distance_to_target <= ATTACK_DISTANCE) {
		target->deal_damage(damage);
	}
	// Close the distance
}
