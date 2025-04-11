#pragma once

#include <iostream>
#include "Role.h"

namespace Model::Roles {

    class NoRole final : public Role {
    public:
        void work(View::AntDrawable& drawable_ant, View::FoodMap& food_map) override {
        }

        [[nodiscard]] NoRole* clone() const override;

        [[nodiscard]] std::string get_name() const override {
            return "No role";
        }
    };

}
