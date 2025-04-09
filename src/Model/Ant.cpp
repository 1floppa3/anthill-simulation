#include <iostream>
#include "Ant.h"
#include "Roles/Cleaner.h"
#include "Roles/Forager.h"
#include "Roles/Soldier.h"
#include "Roles/Caretaker.h"
#include "Roles/NoRole.h"


Ant::Ant(const int age, const int health, const sf::Vector2u& area, const sf::Font& font):
age(age), health(health), role(new NoRole), drawable(new View::AntDrawable(area, font)) {
    std::cout << "New ant with age " << age << '\n';
}

Ant::Ant(const Ant& other):
age(other.age), health(other.health),
role(other.role ? other.role->clone() : nullptr), drawable(other.drawable ? other.drawable->clone() : nullptr) {
    std::cout << "Copy ant with age " << other.age << '\n';
}

Ant& Ant::operator=(const Ant& other) {
    if (this != &other) {
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
    std::cout << "Delete ant with age " << age << '\n';
    delete role;
    delete drawable;
}

void Ant::do_work() const {
    role->work(*drawable);
}

void Ant::update_role() {
    Role *temp = get_new_role();
    if (temp != nullptr) {
        delete role;
        role = temp;
    }
}

// TODO: change
Role *Ant::get_new_role() const {
    if (age > 40 && dynamic_cast<Cleaner *>(role) == nullptr)
        return new Cleaner;
    if (age > 30 && dynamic_cast<Forager *>(role) == nullptr)
        return new Forager;
    if (age > 20 && dynamic_cast<Soldier *>(role) == nullptr)
        return new Soldier;
    if (age > 10 && dynamic_cast<Caretaker *>(role) == nullptr)
        return new Caretaker;
    if (dynamic_cast<NoRole *>(role) == nullptr)
        return new NoRole;
    return nullptr;
}

bool Ant::is_alive() const {
    return health > 0;
}