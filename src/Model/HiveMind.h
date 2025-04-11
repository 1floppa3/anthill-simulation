#ifndef ANTHILL_SIMULATION_HIVEMIND_H
#define ANTHILL_SIMULATION_HIVEMIND_H

#include <map>
#include <SFML/System/Vector2.hpp>
#include "FoodPoint.h"

class HiveMind {
    std::map<FoodPoint*, bool> food_points;
public:
    float x_anthill = 500, y_anthill= 500;
    void add_point(FoodPoint* food_point);
    void remove_point(FoodPoint* food_point);
    FoodPoint* get_food_point();
};


#endif //ANTHILL_SIMULATION_HIVEMIND_H
