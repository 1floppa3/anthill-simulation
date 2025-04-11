#pragma once

#include "Role.h"

namespace Model::Roles {

    class Soldier final : public Role {
    public:
        void work(View::AntDrawable &drawable_ant, View::FoodMap &food_map)  override;

        [[nodiscard]] Soldier *clone() const override;

        [[nodiscard]] std::string get_name() const override {
            return "Soldier";
        }
    };

}