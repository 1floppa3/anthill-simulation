#pragma once

#include <list>
#include <map>
#include "Ant.h"
#include "../View/AnthillDrawable.h"
#include "HiveMind.h"

enum class ResourceType {
    FOOD,
    WOOD
};

class Anthill {
    struct Rank {
        int wood_to_update, ants_capacity, wood_to_maintain;
    };

    static constexpr int max_rank = 4;
    constexpr static Rank anthill_ranks[max_rank + 1] = {{0,  0,  0},
                                                       {10, 10, 2},
                                                       {15, 20, 4},
                                                       {20, 30, 6},
                                                       {25, 40, 8}};
    int rank;
    std::map<ResourceType, int> resources;
public:
    HiveMind hive_mind;

    int day_counter;
    View::AnthillDrawable* drawable;
    std::list<Ant> ants;

    Anthill(int rank);

    Anthill();

    void simulate_day();

    void aliment_ants();

    void maintain_anthill();

    void update_size();

    void iterate_ants(void (const Ant& ant));
};
