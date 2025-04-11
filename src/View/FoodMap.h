#pragma once

#include "../View/FoodPoint.h"
#include "AntDrawable.h"

namespace View {

    class FoodMap final : public sf::Drawable {
        const float area_margin = 50.f;
        struct Food {
            FoodPoint* point;
            bool reserved;
        };

        std::vector<Food> food_points;
        int stored_food = 0;
    public:
        void generate_food(const sf::Vector2f& area);
        void add_food(FoodPoint* food_point);
        void store_food(const FoodPoint* food_point);

        [[nodiscard]] int get_stored_food() const;
        void spend_meal();

        FoodPoint* find_closest_food(const AntDrawable& drawable);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };

}
