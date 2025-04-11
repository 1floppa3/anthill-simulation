#pragma once

#include "Roles/Role.h"
#include "HiveMind.h"

class Ant {
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

    void do_work(HiveMind& hive_mind) const;
    void update_role();

    [[nodiscard]] bool is_alive() const;
};