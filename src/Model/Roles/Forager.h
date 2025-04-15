#pragma once

#include "Role.h"

namespace Model::Roles {

    class Forager final : public Role {
        View::FoodPoint* food_point;
        bool is_bringing;
    public:
        Forager();
        void work(View::AntDrawable& drawable_ant, Model::HiveMind& hive_mind) override;
        [[nodiscard]] Forager* clone() const override;
        [[nodiscard]] std::string get_name() const override {
            return "Forager";
        }
    };

}