#include "Ant.h"

#include "../Core/Simulation.h"
#include "Roles/Cleaner.h"
#include "Roles/Forager.h"
#include "Roles/NoRole.h"

namespace Model {
    int Ant::counter = 0;

    Ant::Ant(const int age, const int health, const sf::Vector2u &area):
    id(++counter), age(age), health(health), role(new Roles::NoRole), drawable(new View::AntDrawable(area)) {
        Core::g_logger.add_message("New ant #" + std::to_string(id) + " is born.");
    }

    Ant::Ant(const Ant &other):
    id(other.id), age(other.age), health(other.health), role(other.role ? other.role->clone() : nullptr),
    drawable(other.drawable ? other.drawable->clone() : nullptr) {}

    Ant &Ant::operator=(const Ant &other) {
        if (this != &other) {
            id = other.id;
            age = other.age;
            health = other.health;
            delete role;
            delete drawable;
            role = other.role ? other.role->clone() : nullptr;
            drawable = other.drawable ? other.drawable->clone() : nullptr;
        }
        return *this;
    }

    Ant::~Ant() {
        delete role;
        delete drawable;
        Core::g_logger.add_message("Ant #" + std::to_string(id) + " is dead. Role: " + role->get_name() + '.');
    }

    void Ant::do_work(View::FoodMap &food_map) const {
        role->work(*drawable, food_map);
    }

    void Ant::update_role() {
        Roles::Role *temp = get_new_role();
        if (temp != nullptr) {
            delete role;
            role = temp;
            Core::g_logger.add_message("Ant #" + std::to_string(id) + " got new role: " + role->get_name() + '.');
        }
    }

    // TODO: change
    Roles::Role *Ant::get_new_role() const {
        if(age > 5 && dynamic_cast<Roles::Forager *>(role) == nullptr)
            return new Roles::Forager;
        return nullptr;
        //    if (age > 40 && dynamic_cast<Cleaner *>(role) == nullptr)
        //        return new Cleaner;
        //    if (age > 30 && age < 40 && dynamic_cast<Forager *>(role) == nullptr)
        //        return new Forager;
        //    if (age > 20 && age < 30 && dynamic_cast<Soldier *>(role) == nullptr)
        //        return new Soldier;
        //    if (age > 10 && age < 20 && dynamic_cast<Caretaker *>(role) == nullptr)
        //        return new Caretaker;
        //    if (age < 10 && dynamic_cast<NoRole *>(role) == nullptr)
        //        return new NoRole;
        //    return nullptr;
    }

    bool Ant::is_alive() const {
        return health > 0;
    }

}