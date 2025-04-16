#pragma once

#include <SFML/Graphics.hpp>

#include "Roles/Role.h"
#include "HiveMind.h"
#include "Entity.h"

namespace Model {

    class Ant: public Entity {
        [[nodiscard]] Roles::Role *get_new_role() const;
        static int counter;

    public:
        int id, age;
        Roles::Role *role;
        View::AntDrawable *drawable;

        Ant() = default;
        Ant(int age, const sf::Vector2u &area);
        Ant(const Ant& other);
        Ant& operator=(const Ant& other);

        ~Ant();

        void do_work(Model::HiveMind& hive_mind) const;
        void detect_objects(Core::EventManager& event_manager) const;
        void update_role();
    };

}