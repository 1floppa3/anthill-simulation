#ifndef ANTHILL_SIMULATION_EVENTMANAGER_H
#define ANTHILL_SIMULATION_EVENTMANAGER_H


#include <list>
#include "../Model/FoodPoint.h"

class EventManager {
public:
    std::list<FoodPoint> food_points;
    void spawn_food();
};


#endif //ANTHILL_SIMULATION_EVENTMANAGER_H
