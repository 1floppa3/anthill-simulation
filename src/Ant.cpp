#include <iostream>
#include "Ant.h"
#include "Roles/Cleaner.h"
#include "Roles/Forager.h"
#include "Roles/Soldier.h"
#include "Roles/Caretaker.h"


Ant::Ant() : age(0), health(0), role(nullptr), pic(nullptr) {

}

Ant::Ant(int age, int health, AntDrawable *ant_dr) : age(age), health(health), role(new NoRole), pic(ant_dr) {
    std::cout << age << '\n';
}

Ant::~Ant() {
    std::cout << age << " deleted\n";
    delete role;
    delete pic;
}

void Ant::do_work() const {
    role->work(*pic);
}

void Ant::update_role() {
    Role *temp = get_new_role();
    if (temp != nullptr) {
        delete role;
        role = temp;
    }
}

bool Ant::is_alive() const {
    return health > 0;
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
