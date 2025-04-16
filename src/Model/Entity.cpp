#include "Entity.h"
#include "../Utils/Random.h"

namespace Model {
    bool Entity::is_alive() const {
        return health > 0;
    }

    void Entity::deal_damage(Entity &entity) const {
        entity.take_damage(damage);
    }

    void Entity::take_damage(int damage) {
        health -= damage;
    }

    Entity::Entity() : damage(Utils::Random::random(5, 15)), is_fighting(false), health(Utils::Random::random(10, 40)) {
    }

    Entity::Entity(int damage, int health) : damage(damage), is_fighting(false), health(health) {}

    Entity::Entity(const Entity &entity) : damage(entity.damage), is_fighting(false), health(entity.health) {

    }
}
