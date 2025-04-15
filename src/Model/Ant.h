#pragma once

#include "Roles/Role.h"
#include "HiveMind.h"
#include "IAttackable.h"

class Ant : public IAttackable {
    [[nodiscard]] Role *get_new_role() const;

public:
    int age, health;
    Role *role;
    View::AntDrawable *drawable;

    Ant() = default;
    Ant(int age, int health, const sf::Vector2u &area, const sf::Font& font);
    Ant(const Ant& other);
    Ant& operator=(const Ant& other);

    ~Ant();

    sf::Vector2f get_position() const override { return drawable->get_position(); }

    void deal_damage(int damage) override;
    
    void do_work(HiveMind& hive_mind) const;
    void update_role();

    [[nodiscard]] bool is_alive() const;
};