#pragma once

#include "Role.h"

class Forager final : public Role {
    FoodPoint* food_point;
    bool is_bringing;
public:
    Forager();
    void work(View::AntDrawable& drawable_ant, HiveMind& hive_mind) override;
    [[nodiscard]] Forager* clone() const override;
    [[nodiscard]] std::string get_name() const override {
        return "Forager";
    }
};
