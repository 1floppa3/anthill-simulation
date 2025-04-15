#pragma once

#include <iostream>
#include "Role.h"

namespace Model::Roles {

    class NoRole final : public Role {
    public:
        void work(View::AntDrawable &drawable_ant, Model::HiveMind &hive_mind) override {
        }
        [[nodiscard]] NoRole *clone() const override;
        [[nodiscard]] std::string get_name() const override {
            return "No role";
        }
        [[nodiscard]] sf::Color get_ant_color() const override {
            return sf::Color::White;
        }
    };

}
