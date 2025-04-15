#pragma once

#include <map>
#include "../View/FoodPoint.h"
#include "../View/AntDrawable.h"

namespace Model {

    class FoodMap final : public sf::Drawable {

        std::map<View::FoodPoint*, bool> food_points;
        int& stored_food;
    public:
        FoodMap(int& store);
        void add_food(View::FoodPoint* food_point);
        void store_food(View::FoodPoint* food_point);

        [[nodiscard]] int get_stored_food() const;
        void spend_meal();

        View::FoodPoint* find_closest_food(const View::AntDrawable& drawable);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };

}
