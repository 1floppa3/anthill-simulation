#include <iostream>
#include "HiveMind.h"
namespace Model{
    HiveMind::HiveMind(Store &food_store, Store &wood_store) {
        food_map = new FoodMap(food_store);
        wood_map = new WoodMap(wood_store);
    }

    View::FoodPoint *HiveMind::find_closest_food(const View::AntDrawable &drawable) {
        return food_map->find_closest_food(drawable);
    }

    void HiveMind::store_food(View::FoodPoint *food_point) {
        food_map->store_food(food_point);
    }

    Model::FoodMap *HiveMind::get_food_map() {
        return food_map;
    }

    void HiveMind::add_food(View::FoodPoint *food_point) {
        food_map->add_food(food_point);
    }

    void HiveMind::store_wood(View::WoodPoint *wood_point) {
        wood_map->store_wood(wood_point);
    }

    void HiveMind::add_wood(View::WoodPoint *wood_point) {
        wood_map->add_wood(wood_point);
    }

    Model::WoodMap *HiveMind::get_wood_map() {
        return wood_map;
    }

    View::WoodPoint *HiveMind::find_closest_wood(const View::AntDrawable &drawable) {
        return wood_map->find_closest_wood(drawable);
    }
}