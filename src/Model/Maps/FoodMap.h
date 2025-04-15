#pragma once

#include <map>
#include "../../View/Points/FoodPoint.h"
#include "../../View/AntDrawable.h"
#include "../Store.h"
#include "Map.h"

namespace Model {

    class FoodMap final : public Map {
    public:
        explicit FoodMap(Model::Store& store);
        void add_food(View::FoodPoint* food_point);
        void store_food(View::FoodPoint* food_point);

        View::FoodPoint* find_closest_food(const View::AntDrawable& drawable);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };

}
