#ifndef ATTACKABLE_H
#define ATTACKABLE_H

#include "SFML/System/Vector2.hpp"

class IAttackable {
public:
	virtual void deal_damage(int damage) = 0;
	virtual sf::Vector2f get_position() const = 0;
};

class AttackablePlaceholder : public IAttackable {
public:
	sf::Vector2f position;
	void deal_damage(int damage) override {}
	sf::Vector2f get_position() const override { return position; }
};

#endif
