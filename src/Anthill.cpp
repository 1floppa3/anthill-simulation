#include "Anthill.h"

Anthill::Anthill(int rank) : rank(rank) {}

Anthill::Anthill() : rank(1) {}

void Anthill::simulateDay() {
    if (rank <= 0)
        return;

    for (auto &ant: ants) {
        ant.doWork();
    }

    // Remove killed ants
    for (auto it = ants.begin(); it != ants.end();) {
        if (!it->isAlive())
            it = ants.erase(it);
        else
            ++it;
    }

    alimentAnts();
    maintainAnthill();

    updateSize();
}

void Anthill::updateSize() {
    if (resources[ResourceType::WOOD] >= anthillRanks[rank].woodToUpdate && rank < maxRank) {
        resources[ResourceType::WOOD] -= anthillRanks[rank].woodToUpdate;
        ++rank;
    }
    if (resources[ResourceType::WOOD] < 0 && rank > 0) {
        resources[ResourceType::WOOD] = 0;
        --rank;
    }
}

void Anthill::maintainAnthill() {

}

void Anthill::alimentAnts(){

}
