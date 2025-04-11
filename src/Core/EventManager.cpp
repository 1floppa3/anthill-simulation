#include "EventManager.h"
#include "../Utils/Random.h"



void EventManager::spawn_food() {
//    food_points.emplace_back(Utils::Random::random(2000), Utils::Random::random(1000), Utils::Random::random(8));
    food_points.emplace_back(Utils::Random::random(1500), Utils::Random::random(1000), 1);
}
