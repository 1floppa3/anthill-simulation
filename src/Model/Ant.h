#pragma once

#include <SFML/Graphics.hpp>

#include "Roles/Role.h"
#include "HiveMind.h"
#include "IAttackable.h"

namespace Model {
    class Ant : public IAttackable {
        [[nodiscard]] Roles::Role *get_new_role() const;
        static int counter;

    public:
        int id, age;
        float hp;
        Roles::Role *role;
        View::AntDrawable *drawable;

        Ant() = default;
        Ant(int age, float health, const sf::Vector2u &area);
        Ant(const Ant& other);
        Ant& operator=(const Ant& other);
        ~Ant();

        sf::Vector2f get_position() const override { return drawable->get_position(); }
        void deal_damage(int damage) override;

        void do_work(Model::HiveMind& hive_mind) const;
        void detect_objects(Core::EventManager& event_manager) const;
        void update_role();

        [[nodiscard]] bool is_alive() const;
    };

}