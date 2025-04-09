#ifndef ANTHILL_SIMULATION_ANTHILL_H
#define ANTHILL_SIMULATION_ANTHILL_H

#include <list>
#include <map>
#include "Ant.h"

enum class ResourceType {
    FOOD,
    WOOD
};

class Anthill {
    struct Rank {
        int woodToUpdate, antsCapacity, woodToMaintain;
    };
    const static int maxRank = 4;
    constexpr const static Rank anthillRanks[maxRank + 1] = {{0,  0,  0},
                                                             {10, 10, 2},
                                                             {15, 20, 4},
                                                             {20, 30, 6},
                                                             {25, 40, 8}};
    int rank;
    std::list<Ant> ants;
    std::map<ResourceType, int> resources;
public:
    Anthill(int rank);

    Anthill();

    void simulateDay();

    void alimentAnts();

    void maintainAnthill();

    void updateSize();
};

#endif //ANTHILL_SIMULATION_ANTHILL_H
