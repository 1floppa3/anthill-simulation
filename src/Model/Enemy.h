#ifndef ENEMY_H
#define ENEMY_H

#define ATTACK_DISTANCE 1

#include "IAttackable.h"

class Enemy : public IAttackable {
private:
	sf::Vector2f position;
	int hp, damage;
public:
	IAttackable* target;

	Enemy(int hp, int damage, const sf::Vector2f& position) : position(position), hp(hp), damage(damage), target(nullptr) {}

	sf::Vector2f get_position() const override { return position; }

	void deal_damage(int damage) override;

	void attack();
};

#endif