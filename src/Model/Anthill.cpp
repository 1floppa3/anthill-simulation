#include "Anthill.h"
#include <iostream>
#include "../Utils/Random.h"

namespace Model {

    Anthill::Anthill(const AnthillSettings& settings) : day_counter(0), current_rank(0), ranks(settings.get_ranks()),
        drawable(new View::AnthillDrawable()), food_store(ranks[0].food_capacity, settings.get_amount_of_food()),
        wood_store(ranks[0].wood_capacity, settings.get_amount_of_wood()), hp(settings.get_ranks()[0].max_hp) {}

    void Anthill::spawn_initial_ants(const sf::Vector2u& resolution)
    {
        for (int i = 0; i < 7; ++i)
            ants.emplace_back(6, max_ant_hp, resolution);
    }

    void Anthill::simulate_day(const sf::Vector2u& resolution) {
        ++day_counter;
        if (current_rank < ranks.size() - 1 && wood_store.get_supplies() >= ranks[current_rank + 1].wood_to_update) {
            ++current_rank;
            wood_store.decrease(ranks[current_rank].wood_to_update);
            food_store.update_capacity(ranks[current_rank].food_capacity);
            wood_store.update_capacity(ranks[current_rank].wood_capacity);
            hp = ranks[current_rank].max_hp;
            sf::Vector2u anthill_max_area(resolution.x / 3 * 2, resolution.y);
            drawable->expand(anthill_max_area);
        }
        else if (wood_store.get_supplies() >= ranks[current_rank].wood_to_maintain) {
            wood_store.decrease(ranks[current_rank].wood_to_maintain);
            hp += ranks[current_rank].max_hp * 5 / 100;
            if (hp > ranks[current_rank].max_hp)
                hp = ranks[current_rank].max_hp;
        }
        else {
            hp -= 5 * ranks[current_rank].max_hp / 100;
            if (hp <= 0) {
                std::cout << "Game over?\n";
            }
        }

        if (hp < ranks[current_rank].max_hp / 2 && current_rank > 0) {
            --current_rank;
            hp = ranks[current_rank].max_hp;
            wood_store.update_capacity(ranks[current_rank].wood_capacity);
            food_store.update_capacity(ranks[current_rank].food_capacity);
        }

        
        float hp_impact;
        if (food_store.get_supplies() >= food_per_ant * ants.size()) {
            food_store.decrease(food_per_ant * ants.size());
            hp_impact = max_ant_hp * 0.05;
        }
        else {
            hp_impact = -max_ant_hp * 0.05 * (food_per_ant * ants.size() - food_store.get_supplies()) / (food_per_ant * ants.size());
        }

        for (auto& ant : ants) {
            ant.hp += hp_impact;
            if (ant.hp > max_ant_hp)
                ant.hp = max_ant_hp;
            else if (ant.hp < 0)
                ant.hp = 0;
            ++ant.age;
            ant.update_role();
        }

        clear_dead_ants();

        if (ants.size() < ranks[current_rank].ants_capacity) {
            ants.emplace_back(0, max_ant_hp, resolution);
        }
    }

    int Anthill::get_food_count() {
        return food_store.get_supplies();
    }

    int Anthill::get_wood_count() {
        return wood_store.get_supplies();
    }

    void Anthill::clear_dead_ants() {
        for (auto it = ants.begin(); it != ants.end();) {
            if (!it->is_alive())
                it = ants.erase(it);
            else
                ++it;
        }
    }

}
