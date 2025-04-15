#include "Anthill.h"

#include "../Utils/Random.h"

namespace Model {

    Anthill::Anthill(const int rank) : rank(rank), day_counter(0), drawable(new View::AnthillDrawable()), food_store(10),
                                       wood_store(10) {
    }

    void Anthill::simulate_day(const sf::Vector2u& resolution) {
        if (rank <= 0)
            return;
        ++day_counter;

        for (auto &ant: ants) {
            ++ant.age;
            ant.update_role();
        }

        // Расширяем муравейник
        const sf::Vector2u anthill_max_area(resolution.x / 3 * 2, resolution.y); // муравейник будет ток на 2/3 экрана
        drawable->expand(anthill_max_area);

        // Добавляем нового муравья
        if (ants.size() < 10)
            ants.emplace_back(0, Utils::Random::random(10, 40), resolution);

        // Remove killed ants
        for (auto it = ants.begin(); it != ants.end();) {
            if (!it->is_alive())
                it = ants.erase(it);
            else
                ++it;
        }

        //    aliment_ants();
        //    maintain_anthill();
        //
        //    update_size();
    }

    void Anthill::update_size() {
        if (wood_store.get_supplies() >= anthill_ranks[rank].wood_to_update && rank < max_rank) {
           wood_store.decrease(anthill_ranks[rank].wood_to_update);
            ++rank;
        }
        if (wood_store.is_empty() && rank > 0) {
            --rank;
        }
    }
    void Anthill::maintain_anthill() {

    }
    void Anthill::aliment_ants(){

    }

    int Anthill::get_food_count() {
        return food_store.get_supplies();
    }

    int Anthill::get_wood_count() {
        return wood_store.get_supplies();
    }

}
