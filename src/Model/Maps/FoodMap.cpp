#include <iostream>
#include "FoodMap.h"

namespace Model {
    Model::FoodMap::FoodMap(Model::Store& store): Map(store){}

    void FoodMap::add_food(View::FoodPoint *food_point) {
        add_object(food_point);
    }

    void FoodMap::store_food(View::FoodPoint *food_point) {
        store_object(food_point);
    }

    View::FoodPoint *FoodMap::find_closest_food(const View::AntDrawable &drawable) {
        return dynamic_cast<View::FoodPoint *>(find_closest_object(drawable));
    }
}
