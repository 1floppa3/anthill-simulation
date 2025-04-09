#pragma once

#include "Roles/Role.h"
#include "Drawable/AntDrawable.h"

class Ant {
    int age, health;
    Role *role;

    void update_role();
    [[nodiscard]] Role *get_new_role() const;

public:
    AntDrawable *pic;

    Ant() = default;
    Ant(int age, int health, const sf::Vector2u &area);
    Ant(const Ant& other);
    Ant& operator=(const Ant& other);

    ~Ant();

    void do_work() const;

    [[nodiscard]] bool is_alive() const;
};