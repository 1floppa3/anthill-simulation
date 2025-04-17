#pragma once

#include <list>
#include <map>
#include "Ant.h"
#include "../View/AnthillDrawable.h"
#include "Maps/FoodMap.h"
#include "HiveMind.h"
#include "AnthillSettings.h"

namespace Model {

    class Anthill {
        std::vector<AnthillRank> ranks;
        int current_rank, hp;        
        Store food_store, wood_store;
        const float food_per_ant = 0.5;
        const float max_ant_hp = 100;
    public:
        Model::HiveMind hive_mind = Model::HiveMind(food_store, wood_store);
        int day_counter;
        View::AnthillDrawable* drawable;
        std::list<Ant> ants;

        explicit Anthill(const AnthillSettings& settings);

        void spawn_initial_ants(const sf::Vector2u& resolution);

        void simulate_day(const sf::Vector2u& resolution);
        
        int get_food_count();
        int get_wood_count();
        void update_size();
        void clear_dead_ants();
    };

}