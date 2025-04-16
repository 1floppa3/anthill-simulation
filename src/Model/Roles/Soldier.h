#pragma once

#include "Role.h"

namespace Model::Roles {

    class Soldier final : public Role {
    public:
        void work(View::AntDrawable &drawable_ant, Model::HiveMind& hive_mind)  override;
        [[nodiscard]] Soldier *clone() const override;
        [[nodiscard]] std::string get_name() const override {
            return "Soldier";
        }
        [[nodiscard]] sf::Color get_ant_color() const override {
            return {178, 34, 34};
        }
    };

}