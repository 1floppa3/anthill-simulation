#pragma once

#include "Role.h"

namespace Model::Roles {

    class Cleaner final : public Role {
    public:
        void work(View::AntDrawable &drawable_ant, View::FoodMap &hive_mind) override;

        [[nodiscard]] Cleaner *clone() const override;

        [[nodiscard]] std::string get_name() const override {
            return "Cleaner";
        }
    };

}