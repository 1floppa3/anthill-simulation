#include "Anthill.h"

#include "../Utils/Random.h"

namespace Model {

    Anthill::Anthill(const int rank) : rank(rank), day_counter(0), drawable(new View::AnthillDrawable()), food_map(new View::FoodMap()) {
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
        if (resources[ResourceType::WOOD] >= anthill_ranks[rank].wood_to_update && rank < max_rank) {
            resources[ResourceType::WOOD] -= anthill_ranks[rank].wood_to_update;
            ++rank;
        }
        if (resources[ResourceType::WOOD] < 0 && rank > 0) {
            resources[ResourceType::WOOD] = 0;
            --rank;
        }
    }
    void Anthill::maintain_anthill() {

    }
    void Anthill::aliment_ants(){

    }

}
