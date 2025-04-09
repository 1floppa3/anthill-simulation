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
        int wood_to_update, ants_capacity, wood_to_maintain;
    };
    const static int max_rank = 4;
    constexpr const static Rank anthill_ranks[max_rank + 1] = {{0,  0,  0},
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

    void simulate_day();

    void aliment_ants();

    void maintain_anthill();

    void update_size();
};

#endif //ANTHILL_SIMULATION_ANTHILL_H
