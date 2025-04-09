#include "Anthill.h"

Anthill::Anthill(int rank) : rank(rank) {}

Anthill::Anthill() : rank(1) {
    for (int i = 0; i < 10; ++i) {
//        ants.emplace(1, 1, AntDrawable(5));
    }
}

void Anthill::simulate_day() {
    if (rank <= 0)
        return;

    for (auto &ant: ants) {
        ant.do_work();
    }

    // Remove killed ants
    for (auto it = ants.begin(); it != ants.end();) {
        if (!it->is_alive())
            it = ants.erase(it);
        else
            ++it;
    }

    aliment_ants();
    maintain_anthill();

    update_size();
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
