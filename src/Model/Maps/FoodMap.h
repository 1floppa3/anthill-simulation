#pragma once

#include <map>
#include "../../View/FoodPoint.h"
#include "../../View/AntDrawable.h"
#include "../Store.h"

namespace Model {

    class FoodMap final : public sf::Drawable {

        std::map<View::FoodPoint*, bool> food_points;
        Model::Store& store;
    public:
        FoodMap(Model::Store& store);
        void add_food(View::FoodPoint* food_point);
        void store_food(View::FoodPoint* food_point);

        View::FoodPoint* find_closest_food(const View::AntDrawable& drawable);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };

}
