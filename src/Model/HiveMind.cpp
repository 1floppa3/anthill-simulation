#include <iostream>
#include "HiveMind.h"

void HiveMind::add_point(FoodPoint* food_point){
    food_points[food_point] = false;
}

void HiveMind::remove_point(FoodPoint* food_point){
    food_points.erase(food_point);
}

FoodPoint* HiveMind::get_food_point() {
    for (auto& food_point : food_points)
    {
        if (!food_point.second){
            food_point.second = true;
            return food_point.first;
        }
    }
    return nullptr;
}
