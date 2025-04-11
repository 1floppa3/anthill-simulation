#pragma once

#include "Role.h"

class Soldier final : public Role {
public:
    void work(View::AntDrawable &drawable_ant, HiveMind &hive_mind)  override;

    [[nodiscard]] Soldier *clone() const override;

    [[nodiscard]] std::string get_name() const override {
        return "Soldier";
    }
};
