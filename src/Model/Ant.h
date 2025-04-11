#pragma once

#include <SFML/Graphics.hpp>

#include "Roles/Role.h"
#include "../View/FoodMap.h"

namespace Model {

    class Ant {
        [[nodiscard]] Roles::Role *get_new_role() const;
        static int counter;

    public:
        int id, age, health;
        Roles::Role *role;
        View::AntDrawable *drawable;

        Ant() = default;
        Ant(int age, int health, const sf::Vector2u &area);
        Ant(const Ant& other);
        Ant& operator=(const Ant& other);

        ~Ant();

        void do_work(View::FoodMap& food_map) const;
        void update_role();

        [[nodiscard]] bool is_alive() const;
    };

}