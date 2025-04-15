#ifndef ANTHILL_SIMULATION_HIVEMIND_H
#define ANTHILL_SIMULATION_HIVEMIND_H

#include "Maps/FoodMap.h"
#include "../View/WoodPoint.h"
#include "Maps/WoodMap.h"

namespace Model{
    class HiveMind {
    private:
        Model::FoodMap* food_map;
        Model::WoodMap* wood_map;
    public:
        explicit HiveMind(Model::Store& food_store, Model::Store& wood_store);

        Model::FoodMap* get_food_map();
        void store_food( View::FoodPoint* food_point);
        void add_food(View::FoodPoint* food_point);
        View::FoodPoint* find_closest_food(const View::AntDrawable& drawable);

        Model::WoodMap* get_wood_map();
        void store_wood( View::WoodPoint* wood_point);
        void add_wood(View::WoodPoint* wood_point);
        View::WoodPoint* find_closest_wood(const View::AntDrawable& drawable);

    };
}

#endif //ANTHILL_SIMULATION_HIVEMIND_H
